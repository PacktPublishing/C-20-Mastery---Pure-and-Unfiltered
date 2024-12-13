#include <coroutine>
#include <iostream>

struct Awaiter {
	bool await_ready() {
		std::cout << "\tAwaiter:\tawait_ready()\n" ;
		//return false ;//Suspend the coroutine
		return true ;//Don't suspend
	}
	void await_suspend(std::coroutine_handle<> handle) {
		std::cout << "\tAwaiter:\tawait_suspend()\n" ;
	}
	void await_resume() {
		std::cout << "\tAwaiter:\tawait_resume()\n" ;
		
	}
};
struct Task {
	struct promise_type {
		promise_type() {
			std::cout << "\t<promise_type()>\n";
		}
		~promise_type() {
			std::cout << "\t<~promise_type()>\n";
		}
		Task get_return_object() {
			std::cout << "\t<get_return_object()>\n";
			return { std::coroutine_handle<promise_type>::from_promise(*this) };
		}
		std::suspend_never initial_suspend() {
			std::cout << "\t<initial_suspend()>\n";
			return {};
		}
		std::suspend_never final_suspend()noexcept {
			std::cout << "\t<final_suspend()>\n";
			return {};
		}
		void unhandled_exception() {
			std::cout << "\t<unhandled_exception()>\n";

		}
		void return_void() {
			std::cout << "\t<return_void()>\n";

		}

	};
	std::coroutine_handle<promise_type> m_Handle;

	Task(const std::coroutine_handle<promise_type>& handle)
		: m_Handle{ handle } {
		std::cout << "\t<Task()>\n";
	}
	~Task() {
		std::cout << "\t<~Task()>\n";
		//m_Handle.destroy();
	}
};

Task CoFunction() {
	std::cout << "\n\t<Coroutine - Started>\n";
	std::cout << "\t<Coroutine - Executing coroutine function....>\n";
	co_await Awaiter{};
	std::cout << "\t<Coroutine - Returning>\n";
	co_return;
}

int main() {
	std::cout << "main - Calling coroutine\n";
	auto task = CoFunction();
	std::cout << "\nmain - Resuming coroutine\n";
	//task.m_Handle.resume();
	std::cout << "\nmain - Coroutine is done!\n";

}