extern "C" void intentional_panic(const char* message);

int main(int argc, char** argv) {
  intentional_panic(argc > 1 ? argv[1] : "yikes");
  return 0;
}
