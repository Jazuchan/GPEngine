#include <vector>
#include <iostream>
#include <memory>

#include <SDL2/SDL.h>

class Keyboard
{
public:
	bool GetKey( int _keyCode );
	bool GetKeyDown( int _keyCode );
	bool GetKeyUp( int _keyCode );

	void Init();
	void Finish();
	void Update();

private:
	//std::vector<int> m_keyCodes;
	int m_keyCodes;
	Uint8* m_currentKey;
	Uint8* m_previousKey;
};