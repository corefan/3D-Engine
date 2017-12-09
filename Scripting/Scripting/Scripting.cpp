#include "stdafx.h"
#include "Scripting.h"

#include <string>
#include <iostream>
#include <windows.h>
#include <direct.h>

// Mono Include
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/jit/jit.h>

#pragma comment(lib, "mono-2.0-sgen.lib")

SCRIPTING_MANAGER bool ScriptingManager::CompileFile(const char * path)
{
	// Get the path of the project ----
	char my_path[FILENAME_MAX];
	_getcwd(my_path, FILENAME_MAX);

	std::string scriptPath = my_path;
	scriptPath += path;

	// Compile the script -------------
	std::string command = my_path;
	command += "/Mono/bin/mcs " + scriptPath + " -target:library";
	if (system(command.c_str()))
	{
		return true;
	}
	else
	{
		return false;
	}
}


