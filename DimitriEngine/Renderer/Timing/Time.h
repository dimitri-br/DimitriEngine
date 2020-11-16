#pragma once
namespace DimitriEngine {
	class Time
	{
	private:
		static Time* instance;

		Time();

	public:

		static Time* GetInstance();

		float deltaTime;
	};
}


