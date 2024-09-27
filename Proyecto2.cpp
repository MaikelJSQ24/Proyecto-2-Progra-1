#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

static void loadMap(Sprite& sprite, const string& nameOfImage)
{
	Texture* map = new Texture();
	if (!map->loadFromFile(nameOfImage))
	{
		cerr << "Error al cargar la imagen: " << nameOfImage << endl;
		return;
	}
	sprite.setTexture(*map);
}

void clicks(Event& event, Sprite& sprite)
{

	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			if (x >= 67 && x <= 238 && y >= 505 && y <= 540)
			{
				loadMap(sprite, "images/map.png");
			}
		}
	}
}

int main()
{
	RenderWindow window(VideoMode(1280, 720), "Proyecto");
	Texture menu;
	menu.loadFromFile("images/start.png");
	

	Sprite sprite;
	sprite.setTexture(menu);
	while (window.isOpen())
	{
		Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			clicks(event,sprite);
		}
		window.clear(Color::Black);
		window.draw(sprite);
		window.display();
	}

}