# PtxCreator
Windows only tool for compiling cuda source into ptx files and c++ headers for use with Optix

// Build instructions for vs2015

1. clone this repository with the --recursive option to bring in the nanogui submodule. The current Release version of Nanogui does not appear to be stable, at least on my machine, so only use the Debug version PtxCreator for now.

git clone --recursive https://github.com/Hurleyworks/PtxCreator.git

2. Within  the nanogui folder, create a folder named "build"
3. Run cmake, making the "build" folder the "where to build the binaries" folder
3. Compile the Nanogui solution with the default settings
4. Open the PtxCreator.sln in the PtxCreator/Builds/VisualStudio2015 folder and compile the debug version

// notes
The build system assumes that you've installed Optix and Cuda in their default locations.
You'll need to change the "logFolder" path in NanoApp.cpp and the "defaultFolder" in NanoView.h to paths that work on your machine

If you use the "Create Ptx header" option, PtxCreator will generate a c++ header file with the Ptx source embedded in a string so your application doesn't need to load any ptx files from disk.

==============================================================================
#pragma once
#define STRINGIFIED(...) #__VA_ARGS__
#define AS_STRING(...) STRINGIFIED(__VA_ARGS__)
const char * exception0 = AS_STRING(
//
// Generated by NVIDIA NVVM Compiler
//
// Compiler Build ID: CL-22781540
// Cuda compilation tools, release 9.0, V9.0.176
// Based on LLVM 3.4svn
//

.version 6.0
.target sm_30
.address_size 64

	// .globl	_Z9exceptionv
.visible .global .align 1 .b8 sysOutputBuffer[1];
.visible .global .align 8 .b8 theLaunchIndex[8];
.visible .global .align 4 .b8 _ZN21rti_internal_typeinfo14theLaunchIndexE[8] = {82, 97, 121, 0, 8, 0, 0, 0};
.visible .global .align 8 .u64 _ZN21rti_internal_register20reg_bitness_detectorE;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail0E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail1E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail2E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail3E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail4E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail5E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail6E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail7E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail8E;
.visible .global .align 8 .u64 _ZN21rti_internal_register24reg_exception_64_detail9E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail0E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail1E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail2E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail3E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail4E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail5E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail6E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail7E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail8E;
.visible .global .align 4 .u32 _ZN21rti_internal_register21reg_exception_detail9E;
.visible .global .align 4 .u32 _ZN21rti_internal_register14reg_rayIndex_xE;
.visible .global .align 4 .u32 _ZN21rti_internal_register14reg_rayIndex_yE;
.visible .global .align 4 .u32 _ZN21rti_internal_register14reg_rayIndex_zE;
.visible .global .align 8 .b8 _ZN21rti_internal_typename14theLaunchIndexE[6] = {117, 105, 110, 116, 50, 0};
.visible .global .align 4 .u32 _ZN21rti_internal_typeenum14theLaunchIndexE = 4919;
.visible .global .align 16 .b8 _ZN21rti_internal_semantic14theLaunchIndexE[14] = {114, 116, 76, 97, 117, 110, 99, 104, 73, 110, 100, 101, 120, 0};
.visible .global .align 1 .b8 _ZN23rti_internal_annotation14theLaunchIndexE[1];

.visible .entry _Z9exceptionv(

)
{
	ret;
}
);

std::string exception = std::string(exception0);

