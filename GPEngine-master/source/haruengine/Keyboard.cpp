#include "Keyboard.h"

void Keyboard::Init()
{
	SDL_GetKeyboardState(&m_keyCodes);
	m_currentKey = new Uint8[m_keyCodes];
	m_previousKey = new Uint8[m_keyCodes];

	std::memcpy(m_currentKey, SDL_GetKeyboardState(NULL), m_keyCodes);
	std::memcpy(m_previousKey, m_currentKey, m_keyCodes);
}

void Keyboard::Finish()
{
	delete[] m_currentKey;
	delete[] m_previousKey;
}

void Keyboard::Update()
{
	std::memcpy(m_previousKey, m_currentKey, m_keyCodes);  //gets previous key
	std::memcpy(m_currentKey, SDL_GetKeyboardState(NULL), m_keyCodes);

}

bool Keyboard::GetKey(int _keyCode)  //returns the key to true when pressed
{
	return m_currentKey[_keyCode] && !m_previousKey[_keyCode];
}

bool Keyboard::GetKeyDown( int _keyCode )  //continually returns true
{
	return m_currentKey[_keyCode];
}

bool Keyboard::GetKeyUp( int _keyCode )
{
	return m_currentKey[_keyCode] && !m_previousKey[_keyCode];
}
