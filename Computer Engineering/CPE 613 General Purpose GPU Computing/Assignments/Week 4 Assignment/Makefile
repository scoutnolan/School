CC=gcc
CXX=g++
NVCC=nvcc

BLASPATH=/opt/asn/apps/blas_gcc610_avx
CUDAPATH=/opt/asn/apps/cuda_11.7.0

CCFLAGS=-std=c11
CXXFLAGS=-std=c++11 -O4
NVCCFLAGS=-std=c++11

NVCCARCHS=-gencode arch=compute_80,code=sm_80 -gencode arch=compute_70,code=sm_70

TIMERINCPATH=-I$(CUDAPATH)/include -ITimer/include
INCPATH=-Imatmul/include -I$(CUDAPATH)/include -I$(CUDAPATH)/samples/common/inc -I$(GTESTPATH)/include
LIBPATH=-L$(CUDAPATH)/lib64 -L$(GTESTPATH)/lib64
RPATH=-Wl,-rpath=`pwd`/build/lib -Wl,-rpath=`pwd`/$(GTESTPATH)/lib64 -Wl,-rpath=`pwd`/$(CUDAPATH)/lib64
LIBS=-lcudart

.PHONY: clean modules

all: build/lib/libTimer.so build/lib/libmatmul.so build/bin/matmul_test

build/lib/libTimer.so: modules Timer/src/Timer.cpp
	@mkdir -p build/.objects/Timer
	$(CXX) $(CXXFLAGS) -c -fPIC -ITimer/include \
		-I$(CUDAPATH)/include -I$(CUDAPATH)/samples/common/inc\
		-o build/.objects/Timer/Timer.os Timer/src/Timer.cpp
	@mkdir -p build/lib
	$(CXX) -shared -o build/lib/libTimer.so build/.objects/Timer/* \
		-L$(CUDAPATH)/lib64 -lcudart_static
	@mkdir -p build/include
	@ln -sf ../../Timer/include/Timer.hpp build/include/Timer.hpp

build/lib/libmatmul.so: modules matmul/src/matmul.cu
	@mkdir -p build/.objects/matmul
	$(NVCC) -pg $(NVCCFLAGS) $(NVCCARCHS) -Xcompiler -fPIC \
		-Imatmul/include -I$(CUDAPATH)/samples/common/inc \
		-dc -o build/.objects/matmul/matmul.o \
		matmul/src/matmul.cu
	$(NVCC) -pg $(NVCCFLAGS) $(NVCCARCHS) -Xcompiler -fPIC \
		-dlink -o build/.objects/matmul/matmul-dlink.o build/.objects/matmul/matmul.o
	mkdir -p build/lib
	$(CC) -shared -o build/lib/libmatmul.so build/.objects/matmul/* \
		-Wl,-rpath=$(CUDAPATH)/lib64 -L$(CUDAPATH)/lib64 -lcudart
	@mkdir -p build/include
	@ln -sf ../../matmul/include/matmul.h build/include/matmul.h

build/bin/matmul_test: build/lib/libTimer.so build/lib/libmatmul.so \
	matmul/test/src/test.cpp
	@mkdir -p build/bin
	$(NVCC) -Ibuild/include -I$(CUDAPATH)/samples/common/inc \
		-ITimer/include -Imatmul/include \
		-o build/bin/matmul_test matmul/test/src/test.cpp \
		-Xlinker \
		-Lbuild/lib -L$(CUDAPATH)/lib64 \
		-lTimer -lmatmul -lcudart -lcublas -lblas -lgfortran

run: build/bin/matmul_test
	@rm -f *.nsys-rep matmul_test.i* matmul_test.o* core.*
	@echo -ne "gpu\n1\n\n10gb\n1\nampere\nmatmul_test\n" | \
		run_gpu .runTests.sh > /dev/null
	@sleep 5
	@tail -f matmul_test.o*

clean:
	rm -rf build
	rm -f *nsys-rep
	rm -f matmul_test.*
