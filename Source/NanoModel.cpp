
#include "NanoModel.h"

// addCudaFolder
void NanoModel::addCudaInputFolder(const std::string & absolutePath)
{
	ptx.findCudaFiles(absolutePath);
}

// addPtxOutputFolder
void NanoModel::addPtxOutputFolder(const std::string & absolutePath)
{
	ptxOutputPath = absolutePath;
}

// compile
void NanoModel::compile(bool createHeaders)
{
	if (!ptx.getCudaFileCount())
	{
		throw std::runtime_error("There a no cuda files to compile!");
	}

	ptx.createPtxFiles(ptxOutputPath, createHeaders);
}

