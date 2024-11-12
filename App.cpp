#include "App.h"

App::App()
{
	loadTextures(textureMap, "images/map.png");
	loadTextures(textureMapOfRoutes, "images/mapOfRoutes.png");
	loadTextures(textureStart, "images/start.png");
	loadTextures(textureMenu, "images/menu.png");
	loadTextures(textureEdit, "images/editMenu.png");
	sprite.setTexture(textureStart);

	loadMusic(musicStart, "Musica/start.ogg");
	loadMusic(musicMenu, "Musica/menu.ogg");
	loadMusic(musicMap, "Musica/map.ogg");

	musicStart.setLoop(true);
	musicStart.setVolume(10);
	musicStart.play();

	musicMenu.setLoop(true);
	musicMenu.setVolume(10);

	musicMap.setLoop(true);
	musicMap.setVolume(10);

	event = {};

	window.create(VideoMode(1280, 720), "Proyecto");
	windowMenu.create(VideoMode(1280, 720), "Proyecto");
	windowMenu.setVisible(false);
	windowMap.create(VideoMode(1280, 720), "Proyecto");
	windowMap.setVisible(false);
	windowOfRoutes.create(VideoMode(1280, 720), "Proyecto");
	windowOfRoutes.setVisible(false);
	loadFromFile();
}

bool App::loadTextures(Texture& texture, string systemPath)
{
	if (!texture.loadFromFile(systemPath))
	{
		cerr << "Error, no se pudo cargar el archivo: " << systemPath << endl;
		return false;
	}
	return true;
}

bool App::loadMusic(Music& music, string systemPath)
{
	if (!music.openFromFile(systemPath))
	{
		cerr << "Error, no se pudo cargar el archivo: " << systemPath << endl;
		return false;
	}
	return true;
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

void App::createMenu()
{
	musicStart.pause();
	musicMenu.play();
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
			if (isButtonPressed(eventMenu, 524, 747, 214, 254))
			{
				windowMenu.setVisible(false);
				musicMenu.pause();
				loadMap();
			}
			if (isButtonPressed(eventMenu, 524, 753, 306, 342))
			{
				windowMenu.setVisible(false);
				musicMenu.pause();
				seeAllRoutes();
			}
			if (isButtonPressed(eventMenu, 523, 747, 394, 428))
			{
				windowMenu.setVisible(false);
				window.setVisible(true);
				musicMenu.pause();
				musicStart.play();
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
	musicMap.play();
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
				routesList.addRoute(ubications);
				windowMap.close();
				return;
			}

			if (eventMap.type == Event::MouseButtonPressed && eventMap.mouseButton.button == Mouse::Left)
			{
				int clickX = eventMap.mouseButton.x;
				int clickY = eventMap.mouseButton.y;
				if (!isButtonPressed(eventMap, 0, 178, 629, 716) && !isButtonPressed(eventMap, 195, 374, 647, 714))
				{
					string name = nameOfPlace();
					ubications.addNewUbication(clickX, clickY, name);
					cout << "Nodo creado en (" << clickX << ", " << clickY << ") con nombre: " << name << endl;
				}
			}

			if (isButtonPressed(eventMap, 195, 374, 647, 714))
			{
				Route newRoute;
				newRoute.addUbicationsFrom(ubications);
				newRoute.setColor(randomColor());
				newRoute.setName(nameOfRoute());
				routesList.addRoute(newRoute);
				saveRoutesToFile();
				ubications.clearUbications();
			}
			if (isButtonPressed(eventMap, 0, 178, 629, 716))
			{
				windowMap.setVisible(false);
				musicMap.pause();
				createMenu();
			}

		}

		windowMap.clear(Color::Black);
		windowMap.draw(spriteMap);
		drawCircles();
		windowMap.display();
	}

}

void App::seeAllRoutes()
{
	musicMap.play();
	windowOfRoutes.setVisible(true);
	window.setVisible(false);

	spriteMapOfRoutes.setTexture(textureMapOfRoutes);

	Font font;

	while (windowOfRoutes.isOpen())
	{
		Event eventRoutes;
		while (windowOfRoutes.pollEvent(eventRoutes))
		{
			if (eventRoutes.type == Event::Closed)
			{
				windowOfRoutes.close();
			}
			changeColor(eventRoutes);
		}

		windowOfRoutes.clear(Color::Black);
		windowOfRoutes.draw(spriteMapOfRoutes);

		RouteNodo* routeNodo = routesList.getHeadRoute();
		int spaceOfText = 0;
		while (routeNodo != nullptr)
		{
			Route route = routeNodo->getRoute();
			PlaceNodo* current = route.getHead();
			PlaceNodo* prev = nullptr;
			Color routeColor = route.getColor();

			while (current != nullptr)
			{
				CircleShape circle(8);
				circle.setFillColor(routeColor);
				circle.setPosition(current->getX() - circle.getRadius(), current->getY() - circle.getRadius());
				windowOfRoutes.draw(circle);

				Text text;

				if (font.loadFromFile("Font/Adventure Subtitles.ttf"))
				{
					loadFontAndText(windowOfRoutes, font, text, current);
				}

				if (prev != nullptr)
				{

					Vector2f p0(prev->getX(), prev->getY());
					Vector2f p1(prev->getX() + 50, prev->getY() - 50);
					Vector2f p2(current->getX() - 50, current->getY() + 50);
					Vector2f p3(current->getX(), current->getY());

					drawLineCurve(windowOfRoutes, p0, p1, p2, p3, routeColor);
				}

				prev = current;
				current = current->getNext();
			}

			Text routeNameText;
			routeNameText.setFont(font);
			routeNameText.setString(route.getName());
			routeNameText.setCharacterSize(20);
			routeNameText.setFillColor(route.getColor());

			if (route.getHead() != nullptr)
			{
				routeNameText.setPosition(10, spaceOfText);
				windowOfRoutes.draw(routeNameText);
			}
			spaceOfText += 30;


			routeNodo = routeNodo->getNext();
		}

		if (isButtonPressed(eventRoutes, 0, 169, 629, 718))
		{
			windowOfRoutes.setVisible(false);
			musicMap.pause();
			createMenu();
		}

		windowOfRoutes.display();
	}

}

void App::editMenu(Route& route, int clickX, int clickY)
{
	RenderWindow editWindow(VideoMode(400, 400), "Editar");
	spriteEdit.setTexture(textureEdit);

	while (editWindow.isOpen())
	{
		Event editEvent;
		while (editWindow.pollEvent(editEvent))
		{
			if (editEvent.type == Event::Closed)
			{
				editWindow.close();
			}

			if (isButtonPressed(editEvent, 123, 273, 77, 104))
			{
				route.setColor(randomColor());
				cout << "Color cambiado.\n";
				saveRoutesToFile();
				editWindow.close();
			}
			if (isButtonPressed(editEvent, 122, 277, 138, 165))
			{

				PlaceNodo* current = route.getHead();
				while (current != nullptr)
				{
					int posX = current->getX();
					int posY = current->getY();
					int radius = 8;


					if (clickX >= posX - radius && clickX <= posX + radius &&
						clickY >= posY - radius && clickY <= posY + radius)
					{
						route.removeUbication(current->getName());
						cout << "Nodo en (" << posX << ", " << posY << ") eliminado.\n";
						break;
					}
					current = current->getNext();
				}
				saveRoutesToFile();
				editWindow.close();
			}
			if (isButtonPressed(editEvent, 124, 277, 200, 226))
			{
				route.clearRoute();
				cout << "Ruta eliminada\n";
				saveRoutesToFile();
				editWindow.close();
			}
			if (isButtonPressed(editEvent, 124, 276, 261, 287))
			{
				editWindow.close();
			}
		}
		editWindow.clear(Color::Black);
		editWindow.draw(spriteEdit);
		editWindow.display();
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
			if (isButtonPressed(event, 67, 238, 505, 540))
			{
				createMenu();
			}
		}
		if (isButtonPressed(event, 69, 234, 568, 603))
		{
			musicStart.stop();
			window.close();
		}

		window.clear(Color::Black);
		window.draw(sprite);
		window.display();
	}

}

Color App::randomColor()
{
	return Color(rand() % 256, rand() % 256, rand() % 256);
}

void App::drawCircles()
{
	Font font;
	Text text;
	if (!font.loadFromFile("Font/Adventure Subtitles.ttf"))
	{
		printf("Error al cargar fuente.");
	}

	PlaceNodo* current = ubications.getHead();
	PlaceNodo* prev = nullptr;
	while (current != nullptr)
	{
		CircleShape circle(8);
		circle.setFillColor(Color::Black);
		circle.setPosition(current->getX() - circle.getRadius(), current->getY() - circle.getRadius());
		windowMap.draw(circle);

		loadFontAndText(windowMap, font, text, current);
		windowMap.draw(text);

		if (prev != nullptr)
		{
			Vector2f p0(prev->getX(), prev->getY());
			Vector2f p1(prev->getX() + 50, prev->getY() - 50);
			Vector2f p2(current->getX() - 50, current->getY() + 50);
			Vector2f p3(current->getX(), current->getY());

			drawLineCurve(windowMap, p0, p1, p2, p3, Color::Black);
		}

		prev = current;
		current = current->getNext();
	}
}

string App::writeName(string windowTitle, string message)
{
	string name = " ";
	Font font;

	if (!font.loadFromFile("Font/Adventure Subtitles.ttf"))
	{
		printf("No se pudo cargar la fuente Adventure Subtitles");
	}

	Text text("", font, 40);
	text.setFillColor(Color::Black);

	RenderWindow writeName(VideoMode(500, 45), windowTitle);
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
		writeName.clear(Color::White);
		writeName.draw(text);
		writeName.display();
	}
	cout << message << name << endl;
	return name;
}

string App::nameOfRoute()
{
	return writeName("Nombre de la ruta", "Nombre de ruta ingresado: ");
}

string App::nameOfPlace()
{
	return writeName("Nombre del lugar", "Nombre de lugar ingresado: ");
}

void App::loadFontAndText(RenderWindow& window, Font font, Text text, PlaceNodo* nodo)
{
	text.setFont(font);
	text.setString(nodo->getName());
	text.setCharacterSize(15);
	text.setFillColor(Color::White);
	text.setPosition(nodo->getX() + 10, nodo->getY() - 5);
	window.draw(text);
}

void App::drawLines(RenderWindow& window, int x1, int y1, int x2, int y2, Color color)
{
	Vertex line[] =
	{
		Vertex(Vector2f(x1, y1), color), Vertex(Vector2f(x2, y2), color)
	};
	window.draw(line, 2, PrimitiveType::Lines);
}

void App::changeColor(Event& event)
{
	if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Right)
	{
		int clickX = event.mouseButton.x;
		int clickY = event.mouseButton.y;

		RouteNodo* routeNodo = routesList.getHeadRoute();
		while (routeNodo != nullptr)
		{
			Route& route = routeNodo->getRoute();
			PlaceNodo* current = route.getHead();
			while (current != nullptr)
			{
				int posX = current->getX();
				int posY = current->getY();
				int radius = 8;

				if (clickX >= posX - radius && clickX <= posX + radius &&
					clickY >= posY - radius && clickY <= posY + radius)
				{
					cout << "Clic detectado en la ubicacion: " << current->getName() << endl;
					editMenu(route, clickX, clickY);
					break;
				}
				current = current->getNext();
			}
			routeNodo = routeNodo->getNext();
		}
	}
}

void App::drawLineCurve(RenderWindow& window, Vector2f p0, Vector2f p1, Vector2f p2, Vector2f p3, Color color)
{
	int prevX = 0, prevY = 0;
	const int numPoints = 100;
	for (int i = 0; i < numPoints; i++)
	{
		float t = static_cast<float>(i) / static_cast<float>(numPoints - 1);
		float x = (1 - t) * (1 - t) * (1 - t) * p0.x + 3 * (1 - t) * (1 - t) * t * p1.x + 3 * (1 - t) * t * t * p2.x + t * t * t * p3.x;
		float y = (1 - t) * (1 - t) * (1 - t) * p0.y + 3 * (1 - t) * (1 - t) * t * p1.y + 3 * (1 - t) * t * t * p2.y + t * t * t * p3.y;

		if (i > 0)
		{
			drawLines(window, prevX, prevY, x, y, color);
		}

		prevX = x;
		prevY = y;
	}
}

void App::saveRoutesToFile()
{
	ofstream fileOfRoutes;

	fileOfRoutes.open("Rutas.txt");

	if (!fileOfRoutes.is_open())
	{
		cerr << "Error, no se pudo abrir el archivo\n";
		return;
	}

	RouteNodo* routeNodo = routesList.getHeadRoute();
	int routeCount = 1;

	while (routeNodo != nullptr)
	{
		Route& route = routeNodo->getRoute();
		fileOfRoutes << "Ruta:" << routeCount << "\n";
		fileOfRoutes << "Nombre de la ruta:" << route.getName() << "\n";
		PlaceNodo* current = route.getHead();

		while (current != nullptr)
		{
			fileOfRoutes << "Ubicacion:" << current->getName() << " X: " << current->getX() << " Y: " << current->getY() << "\n";
			current = current->getNext();
		}

		fileOfRoutes << "Color de la ruta: " << to_string(route.getColor().r) << ", " << to_string(route.getColor().g) << ", "
			<< to_string(route.getColor().b) << "\n";
		fileOfRoutes << "--------------------------\n";

		routeNodo = routeNodo->getNext();
		routeCount++;
	}
	fileOfRoutes.close();
	cout << "Rutas guardadas en Rutas.txt\n";
}

void App::loadFromFile()
{
	ifstream fileOfRoutes("Rutas.txt");

	if (!fileOfRoutes.is_open()) {
		cerr << "Error, no se pudo abrir el archivo Rutas.txt\n";
		return;
	}

	string line;
	Route* currentRoute = nullptr;
	Color colorRoute;
	while (getline(fileOfRoutes, line))
	{
		if (line.find("Ruta") != string::npos)
		{
			if (currentRoute != nullptr)
			{
				routesList.addRoute(*currentRoute);
			}
			currentRoute = new Route();
		}
		else if (line.find("Nombre de la ruta") != string::npos)
		{
			size_t posNameRoute = line.find("Nombre de la ruta") + 18;
			string routeName = line.substr(posNameRoute);
			currentRoute->setName(routeName);
		}
		else if (line.find("Ubicacion:") != string::npos)
		{
			size_t posName = line.find("Ubicacion:") + 10;
			string name = line.substr(posName, line.find(" X:") - posName);
			size_t posX = line.find("X:") + 2;
			size_t posY = line.find("Y:") + 2;
			int x = stoi(line.substr(posX, line.find(",", posX) - posX));
			int y = stoi(line.substr(posY));

			if (currentRoute != nullptr)
			{
				currentRoute->addNewUbication(x, y, name);
			}
		}
		else if (line.find("Color de la ruta:") != string::npos)
		{
			size_t posColor = line.find("Color de la ruta:") + 17;
			int r = stoi(line.substr(posColor, line.find(",")));
			size_t posFirstComma = line.find(",", posColor);
			size_t posSecondComma = line.find(",", posFirstComma + 1);
			int g = std::stoi(line.substr(posFirstComma + 1, posSecondComma - posFirstComma - 1));
			int b = std::stoi(line.substr(posSecondComma + 1));

			if (currentRoute != nullptr)
			{
				currentRoute->setColor(Color(r, g, b));
			}
		}
	}

	if (currentRoute != nullptr)
	{
		routesList.addRoute(*currentRoute);
	}

	fileOfRoutes.close();
	cout << "Rutas cargadas desde Rutas.txt\n";
}