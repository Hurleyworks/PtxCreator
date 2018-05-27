/*

Distributed under the MIT License (MIT)

Copyright (c) 2018 Steve Hurley

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in the
Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished
to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#pragma once

#include "Standard.h"

struct FileServices
{
	static void copyFiles ( const String & searchFolder, const String & destFolder, const String & wildcards, bool recursive = true )
	{
		DirectoryIterator iter (File (searchFolder), recursive, wildcards.getCharPointer().getAddress());

		while (iter.next())
		{
			File file (iter.getFile());

			String dest = destFolder + "/" + file.getFileName();
			file.copyFileTo(dest);
		}
	}

	static void moveFiles ( const String & searchFolder, const String & destFolder, const String & wildcards )
	{
		DirectoryIterator iter (File (searchFolder), true, wildcards.getCharPointer().getAddress());

		while (iter.next())
		{
			File file (iter.getFile());

			String dest = destFolder + "/" + file.getFileName();
			file.moveFileTo(dest);
		}
	}

	static void getFiles ( const String & searchFolder, StringArray & filesToGet, const String & wildcards, bool recursive = true )
	{
		DirectoryIterator iter (File (searchFolder), recursive, wildcards.getCharPointer().getAddress());

		while (iter.next())
		{
			File file (iter.getFile());
			filesToGet.add( file.getFullPathName() );
		}
	}

	static void getFilesAndFolders(const String & searchFolder, StringArray & filesToGet, const String & wildcards, bool recursive = true)
	{
		DirectoryIterator iter(File(searchFolder), recursive, wildcards.getCharPointer().getAddress(), File::findFilesAndDirectories);

		while (iter.next())
		{
			File file(iter.getFile());
			filesToGet.add(file.getFullPathName());
		}
	}

	static void getFolders(const String & searchFolder, StringArray & foldersToGet, bool recursive = true)
	{
		DirectoryIterator iter(File(searchFolder), recursive, "*", File::findDirectories);

		while (iter.next())
		{
			File file(iter.getFile());
			foldersToGet.add(file.getFullPathName());
		}
	}

	static void copyFolder ( const String & folderToCopy, const String & destFolder, const String & wildcards )
	{
		DirectoryIterator iter (File (folderToCopy), true, wildcards.getCharPointer().getAddress());

		while (iter.next())
		{
			File file (iter.getFile());

			String dest = destFolder + "/" + file.getFileName();
			file.copyFileTo(dest);
		}
	}

	static void getTextFileLines ( const String & filePath, StringArray & lines )
	{
		File file(filePath);
		if( !file.exists() )
			return;
		else
			file.readLines(lines);
	}

	static String findFilePath ( const String & searchFolder, const String & fileName)
	{
		DirectoryIterator iter (File (searchFolder), true, "*");

		while (iter.next())
		{
			File file (iter.getFile());
			if( file.getFileName() == fileName )
				return file.getFullPathName();
		}

		return String::empty;
	}
};