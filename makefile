try.exe: try.cpp
	g++ try.cpp -o try

.PHONY: clean
clean:
	del try.exe