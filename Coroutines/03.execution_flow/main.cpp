#include <coroutine>
#include <iostream>

struct Task {
	struct promise_type {
		promise_type() {
			std::cout << "<promise_type()>\n" ;
		}
		~promise_type() {
			std::cout << "< ~promise_type()>\n" ;
		}
		Task get_return_object() {
			std::cout << "<get_return_object()>\n" ;
			return {std::coroutine_handle<promise_type>::from_promise(*this)} ;
		}
		std::suspend_always initial_suspend() {
			std::cout << "<initial_suspend()>\n" ;
			return {} ;
		}
		std::suspend_never final_suspend()noexcept {
			std::cout << "<final_suspend()>\n" ;
			return {} ;
		}
		void unhandled_exception() {
			std::cout << "<unhandled_exception()>\n" ;
			
		}
		void return_void() {
			std::cout << "<return_void()>\n" ;
			
		}
	};
	std::coroutine_handle<promise_type> m_Handle ;

	Task(const std::coroutine_handle<promise_type>& handle)
		: m_Handle{handle} {
		std::cout << "<Task()>\n";
	}
	~Task() {
		std::cout << "<~Task()>\n" ;
		m_Handle.destroy() ;
	}
};

Task CoFunction() {
	std::cout << "<Coroutine - Started>\n" ;
	std::cout << "<Coroutine - Executing coroutine function....>\n" ;
	std::cout << "<Coroutine - Returning>\n" ;
	co_return ;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF) ;
	std::cout << "main - Calling coroutine\n" ;
	auto task  = CoFunction() ;
	while(!task.m_Handle.done()) {
		std::cout << "\nmain - Resuming coroutine\n" ;
		task.m_Handle.resume() ;
	}

	std::cout << "main - Coroutine is done!\n" ;

}