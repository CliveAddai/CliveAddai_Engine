#include "GameScene.h"

GameScene::GameScene() :shape(nullptr) {

}

GameScene::~GameScene() {
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate() {
	Debug::Info("Creating GameScene", "GameScene.cpp", __LINE__);

	Vertex v;
	std::vector<Vertex> vertexList;
	vertexList.reserve(6);

	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 1.0f);
	vertexList.push_back(v);


	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	v.colour = glm::vec3(1.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 0.0f);
	vertexList.push_back(v);

	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	v.colour = glm::vec3(0.0f, 1.0f, 1.0f);
	vertexList.push_back(v);

	Model* model1 = new Model(ShaderHandler::GetInstance()->GetShader("colourShader"));
	model1->AddMesh(new Mesh(vertexList));
	shape = new GameObject(model1);

	return true;

}

void GameScene::Update(const float deltaTime_) {

}

void GameScene::Render() {
	shape->Render();
}