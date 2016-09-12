EXE := test-panic.exe
RUSTLIB := target/release/test_panic.lib
OBJ := test-panic.obj

all: $(EXE)

$(RUSTLIB):
	cargo build --release

%.obj: %.cpp
	cl -Fo$@ -c -MD -Zi $<

$(EXE): $(RUSTLIB) $(OBJ)
	link -NOLOGO -OUT:$@ -MACHINE:X64 -DEBUG $^ ws2_32.lib userenv.lib shell32.lib advapi32.lib msvcrt.lib

clean:
	rm -f $(RUSTLIB) $(EXE) $(OBJ)
