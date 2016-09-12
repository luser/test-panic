extern "C" void intentional_panic(const char* message);

#ifdef _WIN32
#include <Windows.h>

LONG HandleException(EXCEPTION_POINTERS* exinfo) {
  return EXCEPTION_EXECUTE_HANDLER;
}

void set_exception_handler() {
  SetUnhandledExceptionFilter(HandleException);
}

#endif

int main(int argc, char** argv) {
#ifdef _WIN32
  set_exception_handler();
#endif
  intentional_panic(argc > 1 ? argv[1] : "yikes");
  return 0;
}
