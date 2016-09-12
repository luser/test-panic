extern "C" void intentional_panic(const char* message);

#ifdef _WIN32
#include <Windows.h>

static LONG WINAPI
fault_handler(LPEXCEPTION_POINTERS exception)
{
  return EXCEPTION_CONTINUE_SEARCH;
}

#endif

int main(int argc, char** argv) {
#ifdef _WIN32
  AddVectoredExceptionHandler(1, fault_handler);
#endif
  intentional_panic(argc > 1 ? argv[1] : "yikes");
  return 0;
}
