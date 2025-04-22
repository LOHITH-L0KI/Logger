#ifndef RUN_MODE_ENUM
#define RUN_MODE_ENUM

namespace Logger {

	enum RunMode {

		SEQUENTIAL,
		CONCURRENT_THREAD,
		DEFAULT = SEQUENTIAL
	};
}
#endif // !RUN_MODE_ENUM

