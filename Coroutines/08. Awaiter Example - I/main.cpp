#include <coroutine>
#include <iostream>


struct Task {
	struct promise_type {

		Task get_return_object() {
			return { std::coroutine_handle<promise_type>::from_promise(*this) };
		}
		std::suspend_never initial_suspend() {
			return {};
		}
		std::suspend_never final_suspend()noexcept {
			return {};
		}
		void unhandled_exception() {

		}
		void return_void() {

		}

	};
	std::coroutine_handle<promise_type> m_Handle;

	Task(const std::coroutine_handle<promise_type>& handle)
		: m_Handle{ handle } {
	}
	~Task() {
		m_Handle.destroy();
	}
};

Task GetFileData() {
	std::cout << "\n\t<Coroutine - Acquiring data>\n";
	std::cout << "\t<Coroutine - Finished>\n";
	co_return;
}

int main() {
	std::cout << "main - Starting coroutine\n";
	auto task = GetFileData();
	std::cout << "\nmain - Coroutine is done!\n";
}