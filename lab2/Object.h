#pragma once
#ifndef OBJECT_H
#define OBJECT_H



class Object
{

private:

	bool initilized = true;

public:

	Object();
	~Object();

	void Destroy();
	void initilize();
	bool isInitilized();
	void Load();




};

#endif // !OBJECT_H