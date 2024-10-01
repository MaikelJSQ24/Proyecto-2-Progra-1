#include "App.h"

App::App()
{
	window.create(VideoMode(1280, 720), "Proyecto");
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
	if (!font.loadFromFile("Font/Adventure Subtitles.ttf"))
	{
		printf("Error al cargar fuente de texto Adventure Subtitles");
	}
	sprite.setTexture(textureStart);

	spriteMap.setTexture(textureMap);
	spriteMap.setScale(0.85f,1.00);
	spriteMap.setPosition(0, 0);

	event = {};
	isMapLoad = false;
	createMenu();
}

bool App::clicks(Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.mouseButton.button == Mouse::Left)
		{
			int clickX = event.mouseButton.x;
			int clickY = event.mouseButton.y;
			if (clickX >= 67 && clickX <= 238 && clickY >= 505 && clickY <= 540)
			{
				return true;
			}
			if (clickX >= 1088 && clickX <= 1277 && clickY >= 345 && clickY <= 395)
			{
				window.close();
			}
			
		}
	}
	return false;
}

void App::createMenu()
{
	rectangleOption.setSize(Vector2f(192, 50));
	rectangleOption.setFillColor(Color::White);
	rectangleOption.setPosition(1088, 30);
	
	rectangleCreate.setSize(Vector2f(192, 50));
	rectangleCreate.setFillColor(Color::White);
	rectangleCreate.setPosition(1088, 135);

	rectangleDelete.setSize(Vector2f(192, 50));
	rectangleDelete.setFillColor(Color::White);
	rectangleDelete.setPosition(1088, 240);

	rectangleExit.setSize(Vector2f(192, 50));
	rectangleExit.setFillColor(Color::White);
	rectangleExit.setPosition(1088, 345);

	textOfOption.setFont(font);
	textOfCreate.setFont(font);
	textOfDelete.setFont(font);
	textOfExit.setFont(font);

	textOfOption.setString("Opciones");
	textOfCreate.setString("Crear ruta");
	textOfDelete.setString("Borrar ruta");
	textOfExit.setString("Salir");

	textOfOption.setFillColor(Color::Black);
	textOfCreate.setFillColor(Color::Black);
	textOfDelete.setFillColor(Color::Black);
	textOfExit.setFillColor(Color::Black);

	textOfOption.setPosition(1110, 30);
	textOfCreate.setPosition(1110, 135);
	textOfDelete.setPosition(1100, 240);
	textOfExit.setPosition(1152, 345);
}

void App::loadMap(Event& event, Sprite& spriteMap)
{
	if (clicks(event))
	{
		isMapLoad = true;
	}
}

void App::runApp()
{
	while (window.isOpen())
	{
		Event event{};
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			loadMap(event, spriteMap);
		}
		window.clear(Color::Black);
		if (isMapLoad)
		{
			window.draw(spriteMap);

			window.draw(rectangleOption);
			window.draw(rectangleCreate);
			window.draw(rectangleDelete);
			window.draw(rectangleExit);

			window.draw(textOfOption);
			window.draw(textOfCreate);
			window.draw(textOfDelete);
			window.draw(textOfExit);
			
		}
		else
		{
			window.draw(sprite);
		}
		seeClicks(event);
		window.display();
	}
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
