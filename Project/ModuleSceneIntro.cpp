#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	Cube c1(5, 5, 50);
	Cube c2(5, 5, 50);
	Cube c3(50, 5, 5);

	PhysBody3D* cube = App->physics->AddBody(c1);
	PhysBody3D* cube2 = App->physics->AddBody(c2);
	PhysBody3D* cube3 = App->physics->AddBody(c3);

	cube->SetPos(-5, 2, 50);
	cube->body->setMassProps(0, { 0,0,0 });

	cube2->SetPos(5, 2, 50);
	cube2->body->setMassProps(0, { 0,0,0 });

	cube3->SetPos(50, 2, 5);
	cube3->body->setMassProps(0, { 0,0,0 });

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);

	p.axis = true;
	p.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}

