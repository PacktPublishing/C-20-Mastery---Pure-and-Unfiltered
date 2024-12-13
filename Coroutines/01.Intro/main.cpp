#include <coroutine>
#include <iostream>

struct Task {
	struct promise_type ;
	using Handle = std::coroutine_handle<promise_type> ;
	struct promise_type {
		Task get_return_object() {
			return {Handle::from_promise(*this)} ;
		}
		std::suspend_always initial_suspend() {
			return {} ;
		}
		std::suspend_always final_suspend()noexcept {
			return {} ;
		}
		void unhandled_exception() {
			
		}
		void return_void() {
			
		}
	};
	Task(Handle handle):m_Handle{handle} {
		
	}
	~Task() {
		if(m_Handle) {
			m_Handle.destroy() ;
		}
	}
	Handle m_Handle{} ;
};

Task CoFunction() {
	std::cout << "<Coroutine - Started>\n" ;
	std::cout << "<Coroutine - Executing coroutine function>\n" ;
	co_await std::suspend_always{} ;
	std::cout << "<Coroutine - Resuming coroutine...>\n" ;
	std::cout << "<Coroutine - Executing coroutine function>\n" ;
	std::cout << "<Coroutine - Returning>\n" ;

	co_return ;
}

int main() {
	std::cout << "main - Calling coroutine\n" ;
	auto task  = CoFunction() ;
	while(!task.m_Handle.done()) {
		std::cout << "\nmain - Resuming coroutine\n" ;
		task.m_Handle.resume() ;
	}
	std::cout << "main - Coroutine is done!\n" ;

}