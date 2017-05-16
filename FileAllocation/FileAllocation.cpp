// FileAllocation.cpp: главный файл проекта.

// enum_files.cpp  
// compile with: /clr 
#include "stdafx.h"
#using <system.dll> 
using namespace System;
using namespace System::IO;

int main()
{

	String^ folder = "C:\\Files";
	array<String^>^ dir = Directory::GetDirectories(folder);
	Console::WriteLine("--== Directories inside '{0}' ==--", folder);
	for (int i = 0; i < dir->Length; i++)
		Console::WriteLine(dir[i]);

	array<String^>^ file = Directory::GetFiles(folder);
	Console::WriteLine("--== Files inside '{0}' ==--", folder);
	for (int i = 0; i < file->Length; i++)
	{
		Console::WriteLine(file[i]);
		try
		{
			Console::WriteLine("Trying to open file {0}...", file[i]);
			StreamReader^ din = File::OpenText(file[i]);

			String^ str;
			int count = 0;
			while ((str = din->ReadLine()) != nullptr)
			{
				count++;
				Console::WriteLine("Line {0}: {1}", count, str);
			}
		}
		catch (Exception^ e)
		{
			if (dynamic_cast<FileNotFoundException^>(e))
				Console::WriteLine("File '{0}' not found", file[i]);
			else
				Console::WriteLine("Problem reading file '{0}'", file[i]);
		}
	}
	return 0;
}
