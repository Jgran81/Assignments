libshape.so: shape.cpp
    @echo -- Building shared library $@
    g++ --shared -fPIC shape.cpp -o libshape.so
lib: main.cpp libshape.so
    @echo -- Building shapelib.out using libshape.so as a shared library
    @echo -- run "export LD_LIBRARY_PATH=."
    g++ shape_main.cpp -L. -lshape -o shapelib.out