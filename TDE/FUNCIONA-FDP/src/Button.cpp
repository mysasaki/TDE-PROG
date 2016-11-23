#include "Button.h"



Button::Button(float x, float y)
{
	m_x = x;
	m_y = y;
	image.loadImage("images/button.png");
	Reset();
}

void Button::Draw()
{
	image.draw(m_x, m_y, m_width, m_height);
}

void Button::Reset()
{
	m_width = 150;
	m_height = 100;
}

bool Button::WasClicked(int x, int y)
{
	if ((x > m_x && x < m_x + m_width) && (y > m_y && y < m_y + m_height))
		return true;
	return false;
}


Button::~Button()
{
}
