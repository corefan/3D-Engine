#ifndef SCRIPTING_MANAGER_H
#define SCRIPTING_MANAGER_H

#ifdef SCRIPTING_EXPORTS
#define SCRIPTING_MANAGER __declspec(dllexport)
#else
#define SCRIPTING_MANAGER __declspec(dllimport)
#endif

namespace ScriptingManager
{
	SCRIPTING_MANAGER bool CompileFile(const char* path);
}
#endif;