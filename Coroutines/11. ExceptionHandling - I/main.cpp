#include <iostream>
#include <coroutine>

struct Task {
    struct promise_type {
        promise_type() {
            std::cout << "\t< promise_type() >\n";
        }
        ~promise_type() {
            std::cout << "\t< ~promise_type() >\n";
        }
        Task get_return_object() {
            std::cout << "\t< get_return_object() >\n";
            return { std::coroutine_handle<promise_type>::from_promise(*this) };
        }
        std::suspend_never initial_suspend() {
            std::cout << "\t< initial_suspend() >\n";
            return {};
        }
        std::suspend_never final_suspend()noexcept {
            std::cout << "\t< final_suspend() >\n";
            return {};
        }
        void unhandled_exception() {
            std::cout << "\t< unhandled_exception() >\n";
            std::cout << "\t ## RETHROWING EXCEPTION ##\n" ;
            std::rethrow_exception(std::current_exception()) ;
            //terminate() ;
        }
        void return_void() {
         std::cout << "\t< return_void() >\n";
        }

    };
    bool done() {
        return m_Handle.done();
    }
    void resume() {
        if (m_Handle.done()) {
            return;
        }
        m_Handle.resume();
    }
    using Handle = std::coroutine_handle<promise_type>;
    Task(Handle handle) :m_Handle{ handle } {
        std::cout << "\t< Task() >\n";
    }
    ~Task() {
        std::cout << "\t< ~Task() >\n";
    }
private:
    Handle m_Handle{};
};

Task CoFunction() {
    std::cout << "\n\t< CoFunction() - Started & co_await'ed >\n";
	throw std::logic_error{"Crash"} ;
    co_await std::suspend_always{};
    std::cout << "\t< CoFunction() - Resumed >\n";
    co_return;
}

int main() {
    try{
        std::cout << "main() - Calling coroutine\n";
        auto task = CoFunction();
        std::cout << "\nmain() - Resuming coroutine\n";
        task.resume();
        std::cout << "\nmain() - Coroutine done!\n";
    }
    catch (const std::exception& ex) {
        std::cout << "\n#### EXCEPTION ####\n";
        std::cout << ex.what() << '\n';
        std::cout << "###################\n";
    }
}