#include <coroutine>
#include <iostream>

struct Task {
	struct promise_type {
		promise_type() {
			std::cout << "<promise_type()>\n";
		}
		~promise_type() {
			std::cout << "< ~promise_type()>\n";
		}
		Task get_return_object() {
			std::cout << "<get_return_object()>\n";
			return { std::coroutine_handle<promise_type>::from_promise(*this) };
		}
		std::suspend_never initial_suspend() {
			std::cout << "<initial_suspend()>\n";
			return {};
		}
		std::suspend_always final_suspend()noexcept {
			std::cout << "<final_suspend()>\n";
			return {};
		}
		void unhandled_exception() {
			std::cout << "<unhandled_exception()>\n";

		}
		void return_void() {
			std::cout << "<return_void()>\n";
		}
		std::suspend_always yield_value(int value) {
			std::cout << "<yield_value()>\n";
			m_Value = value;
			return {};
		}
		auto await_transform(int x)noexcept {
			std::cout << "\t<await_transform()\n";
			return std::suspend_always{};
		}
		int m_Value{};
	};
	int GetValue()const {
		return m_Handle.promise().m_Value;
	}
	std::coroutine_handle<promise_type> m_Handle;

	Task(const std::coroutine_handle<promise_type>& handle)
		: m_Handle{ handle } {
		std::cout << "Task()\n";
	}
	~Task() {
		std::cout << "~Task()\n";
		m_Handle.destroy();
	}
};

Task CoFunction() {
	std::cout << "<Coroutine - Started>\n";
	std::cout << "<Coroutine - Executing coroutine function>\n";

	std::cout << "<Coroutine - Yielding value>\n";
	co_yield 10;

	std::cout << "<Coroutine - Yielding value>\n";
	co_yield 20;

	std::cout << "<Coroutine - Returning>\n";
	co_return;
}

Task CoGenerate(int begin, int end, int step = 1) {
	for (int i = begin; i < end; i += step) {
		co_yield i;
	}
	co_return;
}
int main() {
	std::cout << "main - Calling coroutine\n";
	/*auto task  = CoFunction() ;
	while(!task.m_Handle.done()) {
		std::cout << "\nmain - Resuming coroutine\n" ;
		std::cout << "main - Value : " << task.GetValue() << '\n' ;
		task.m_Handle.resume() ;
	}*/

	auto gen = CoGenerate(0, 10, 2);
	while (!gen.m_Handle.done()) {
		std::cout << gen.GetValue() << ' ';
		gen.m_Handle.resume();
	}
	std::cout << "main - Coroutine is done!\n";

}



struct Awaitable{
    std::suspend_always operator co_await(){
        std::cout << "<operator co_await()>\n";
        return {};
    }
} ;