#include "ModuleObjects.h"
#include "Primitive.h"
#include "Globals.h"
#include "ModulePhysics3D.h"
#include "PhysBody3D.h"
#include "Application.h"

ModuleObjects::ModuleObjects(bool start_enabled) : Module(start_enabled)
{

}

ModuleObjects::~ModuleObjects()
{

}

bool ModuleObjects::Start()
{
	return true;
}

update_status ModuleObjects::Update(float dt)
{
	//CreateSphere_p

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		Object_id temp;
		temp.id = 3;
		temp.type = SPHERE;
		sphere_ID.push_back(temp);
	}
	/*std::list<PhysBody3D*>::iterator item_sphere = Body_spheres.begin();
	for (int i = 0; i < Body_spheres.size(); i++)
	{
		item_sphere._Ptr->_Myval->GetTransform(&(spheres[i].sphere.transform));
		spheres[i].sphere.Render();
		item_sphere++;
	}

	std::list<PhysBody3D*>::iterator item_cube = Body_cubes.begin();
	for (int i = 0; i < Body_cubes.size(); i++)
	{
		item_cube._Ptr->_Myval->GetTransform(&(cubes[i].cube.transform));
		cubes[i].cube.Render();
		item_cube++;
	}*/


	/*for (int i = 0; i < spheres_mathgeo.size(); i++)
	{
		RenderSphere(&spheres_mathgeo[i].sphere, spheres_mathgeo[i].color, wireframe_mode);
	}*/
	for (int i = 0; i < sphere_ID.size(); i++)
	{
		Render(sphere_ID[i]);
	}

	return UPDATE_CONTINUE;
}

bool ModuleObjects::CleanUp()
{
	return true;
}


void ModuleObjects::Render(Object_id id)
{
	switch (id.type)
	{
	case SPHERE:
		RenderSphere(id.id);
		break;
	case CUBE:
		RenderCube(id.id);
		break;
	default:
		break;
	}
}

void ModuleObjects::CreateSphere(Sphere* sphere/*, ImVec4 color/*, bool isKynematic*/)
{
	if (sphere != NULL)
	{
		/*Sphere_mathgeo_object temp;
		temp.sphere = *sphere;
		temp.isKynematic = isKynematic;
		temp.color.r = color.x;
		temp.color.g = color.y;
		temp.color.b = color.z;
		temp.color.a = color.w;
		spheres_mathgeo.push_back(temp);*/

		Sphere* sphe = sphere;

		float3 array_v1[1536];
		float3 array_v2[1536];
		sphe->Triangulate(array_v1, array_v2, NULL, 1536, false);
		GLuint ver;
		glGenBuffers(1, &ver);
		glBindBuffer(GL_ARRAY_BUFFER, ver);
		glBufferData(GL_ARRAY_BUFFER, sizeof(array_v1), &array_v1, GL_STATIC_DRAW);
		Object_id temp;
		temp.id = ver;
		temp.type = SPHERE;
		sphere_ID.push_back(temp);

		/*if (isKynematic)
		{
			Body_spheres_mathgeo.push_back(App->physics->AddBody(*sphere, 0.0f));
		}
		else
		{
			Body_spheres_mathgeo.push_back(App->physics->AddBody(*sphere));
		}*/
	}
}

void ModuleObjects::CreateCube(OBB* cube/*, ImVec4 color/*, bool isKynematic*/)
{

	/*float3 array_v1[36];
	float3 array_v2[36];
	cube->Triangulate(3,3,3,array_v1, array_v2, NULL, false);
	/*GLuint ver;
	glGenBuffers(1, &ver);
	glBindBuffer(GL_ARRAY_BUFFER, ver);
	glBufferData(GL_ARRAY_BUFFER, sizeof(array_v1), &array_v1, GL_STATIC_DRAW);*/
	/*Object_id temp;
	temp.id = ver;
	temp.type = CUBE;
	sphere_ID.push_back(&temp);*/

}

void ModuleObjects::RenderSphere(GLuint id/*, bool wire*/)
{
	if (wireframe_mode)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	//glColorPointer(3, GL_FLOAT, 1, &color);
	// � draw other buffers
	glDrawArrays(GL_TRIANGLES, 0, 512 * 3);
	glDisableClientState(GL_VERTEX_ARRAY);
	if (wireframe_mode)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

}

void ModuleObjects::RenderCube(GLuint id/*, ImVec4 color*/)
{
	if (wireframe_mode)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glEnableClientState(GL_VERTEX_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, id);
	glVertexPointer(3, GL_FLOAT, 0, NULL);
	//glColorPointer(3, GL_FLOAT, 1, &color);
	// � draw other buffers
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDisableClientState(GL_VERTEX_ARRAY);

	if (wireframe_mode)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void ModuleObjects::ShowAxis(bool axis)
{
	/*for (int i = 0; i < Body_spheres.size(); i++)
	{
		spheres[i].sphere.axis = axis;
	}
	for (int i = 0; i < Body_cubes.size(); i++)
	{
		cubes[i].cube.axis = axis;
	}*/
}

void ModuleObjects::ShowWire(bool wire)
{
	wireframe_mode = wire;
	/*for (int i = 0; i < Body_spheres.size(); i++)
	{
		spheres[i].sphere.wire = wire;
	}
	for (int i = 0; i < Body_cubes.size(); i++)
	{
		cubes[i].cube.wire = wire;
	}*/

}

/*void ModuleObjects::CreateSphere(Sphere_p* sphere, ImVec4 color, bool isKynematic)
{
if (sphere != NULL)
{
Sphere_object temp;
temp.sphere = *sphere;
temp.isKynematic = isKynematic;
temp.sphere.color.r = color.x;
temp.sphere.color.g = color.y;
temp.sphere.color.b = color.z;
temp.sphere.color.a = color.w;
spheres.push_back(temp);
if (isKynematic)
{
Body_spheres.push_back(App->physics->AddBody(*sphere, 0.0f));
}
else
{
Body_spheres.push_back(App->physics->AddBody(*sphere));
}
}
}*/

/*void ModuleObjects::CreateCube(Cube_p* cube, ImVec4 color, bool isKynematic)
{
if (cube != NULL)
{
Cube_object temp;
temp.cube = *cube;
temp.isKynematic = isKynematic;
temp.cube.color.r = color.x;
temp.cube.color.g = color.y;
temp.cube.color.b = color.z;
temp.cube.color.a = color.w;
cubes.push_back(temp);
if (isKynematic)
{
Body_cubes.push_back(App->physics->AddBox(*cube, 0.0f));
}
else
{
Body_cubes.push_back(App->physics->AddBox(*cube));
}
}
}*/
