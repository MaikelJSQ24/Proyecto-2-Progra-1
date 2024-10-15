#include "App.h"

App::App()
{
	if (!textureMap.loadFromFile("images/map.png"))
	{
		printf("Error al cargar la imagen mapa\n");
	}
	if (!textureStart.loadFromFile("images/start.png"))
	{
		printf("Error al cargar la imagen start\n");
	}
	if (!textureMenu.loadFromFile("images/menu.png"))
	{
		printf("Error al cargar la imagen menu\n");
	}
	sprite.setTexture(textureStart);

	event = {};

	window.create(VideoMode(1280, 720), "Proyecto");
	windowMenu.create(VideoMode(1280, 720), "Proyecto");
	windowMenu.setVisible(false);
	windowMap.create(VideoMode(1280, 720), "Proyecto - Mapa");
	windowMap.setVisible(false);
}

bool App::isButtonPressed(Event& event, int x1, int x2, int y1, int y2)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			int clickX = event.mouseButton.x;
			int clickY = event.mouseButton.y;
			if (clickX >= x1 && clickX <= x2 && clickY >= y1 && clickY <= y2)
			{
				return true;
			}
		}
	}
	return false;
}

void App::seeClicks(Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			int x = event.mouseButton.x;
			int y = event.mouseButton.y;
			cout << "X=" << x << ", Y=" << y << endl;
		}
	}
}

void App::loadWindows(Event& event)
{
	if (isButtonPressed(event, 67, 238, 505, 540))
	{
		createMenu();
	}
}

void App::createMenu()
{
	windowMenu.setVisible(true);
	window.setVisible(false);

	spriteMenu.setTexture(textureMenu);
	while (windowMenu.isOpen())
	{
		Event eventMenu;
		while (windowMenu.pollEvent(eventMenu))
		{
			if (eventMenu.type == Event::Closed)
			{
				windowMenu.close();
				return;
			}
			seeClicks(eventMenu);
			if (isButtonPressed(eventMenu, 534, 736, 212, 247))
			{
				windowMenu.setVisible(false);
				loadMap();
			}
			if (isButtonPressed(eventMenu, 532, 741, 457, 494))
			{
				windowMenu.setVisible(false);
				window.setVisible(true);
				runApp();

			}
		}

		windowMenu.clear(Color::Black);
		windowMenu.draw(spriteMenu);
		windowMenu.display();
	}
}

void App::loadMap()
{
	windowMap.setVisible(true);
	window.setVisible(false);

	spriteMap.setTexture(textureMap);
	while (windowMap.isOpen())
	{
		Event eventMap;
		while (windowMap.pollEvent(eventMap))
		{
			if (eventMap.type == Event::Closed)
			{
				windowMap.close();
				return;
			}
			seeClicks(eventMap);

			if (eventMap.type == Event::MouseButtonPressed && eventMap.mouseButton.button == Mouse::Left)
			{
				int clickX = eventMap.mouseButton.x;
				int clickY = eventMap.mouseButton.y;
				if (!isButtonPressed(eventMap, 0, 169, 629, 718))
				{
					string name = namePlace();

					ubications.addNewUbication(clickX, clickY, name);
					cout << "Nodo creado en (" << clickX << ", " << clickY << ")con nombre: " << name << endl;
				}
			}

			if (isButtonPressed(eventMap, 0, 169, 629, 718))
			{
				windowMap.setVisible(false);
				createMenu();
			}

		}

		windowMap.clear(Color::Black);
		windowMap.draw(spriteMap);
		drawCircles();
		windowMap.display();
	}
}

void App::runApp()
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			seeClicks(event);
			loadWindows(event);
		}
		if (isButtonPressed(event, 69, 234, 568, 603))
		{
			window.close();
		}

		window.clear(Color::Black);
		window.draw(sprite);
		window.display();
	}
}

void App::drawCircles()
{
	Font font;
	if (!font.loadFromFile("Font/Adventure Subtitles.ttf"))
	{
		printf("Error al cargar fuente.");
	}

	Nodo* current = ubications.getHead();
	while (current != nullptr)
	{
		CircleShape circle(8);
		circle.setFillColor(Color::Red);
		circle.setPosition(current->getX() - circle.getRadius(), current->getY() - circle.getRadius());
		windowMap.draw(circle);

		Text text;
		text.setFont(font);
		text.setString(current->getName());
		text.setCharacterSize(20);
		text.setFillColor(Color::White);
		text.setPosition(current->getX() + 10, current->getY() - 5);
		windowMap.draw(text);

		current = current->getNext();

	}
}

string App::namePlace()
{
	string name = " ";
	Font font;

	if (!font.loadFromFile("Font/Adventure Subtitles.ttf"))
	{
		printf("No se pudo cargar la fuente Adventure Subtitles");
	}
	
	Text text("", font, 12);
	text.setFillColor(Color::Red);
	
	RenderWindow writeName(VideoMode(200,50), "Nombre del lugar");
	while (writeName.isOpen())
	{
		Event eventWrite;
		while (writeName.pollEvent(eventWrite))
		{
			if (eventWrite.type == Event::Closed)
			{
				writeName.close();
			}

			if (eventWrite.type == Event::TextEntered)
			{
				if (eventWrite.text.unicode < 128)
				{
					if (eventWrite.text.unicode == '\b')
					{
						if (!name.empty())
						{
							name.pop_back();
						}
					}
					else if (eventWrite.text.unicode == '\r')
					{
						writeName.close();
					}
					else
					{
						name += static_cast<char>(eventWrite.text.unicode);
					}
				}
			}
		}

		text.setString(name);
		writeName.clear(Color::Black);
		writeName.draw(text);
		writeName.display();
	}
	cout << "Nombre del lugar ingresado: " << name << endl;
	return name;
}
