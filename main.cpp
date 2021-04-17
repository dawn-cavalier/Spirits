#include <iostream>
#include <SFML/Graphics.hpp>

sf::Text howToSetText(std::string);

int main() {
    // TODO: Set width and height modifications
    sf::RenderWindow window(sf::VideoMode(800, 600), "");
    // Framerate limitor?
    // window.setFramerateLimit(60);


    while(window.isOpen()) {
        /// Event processing
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        /// Drawing
        // Clear window each frame to draw new stuff
        window.clear();
        // The content in order of layer

        // End the current frame and display its contents on screen
        window.display();
    }
    return 0;
}

sf::Text howToSetText(std::string input) {
    sf::Text temp;
    // Need to get and assign font
    sf::Font font;
    if(!font.loadFromFile("..\\Assets\\TempFonts\\PixelFont.ttf")) {
        std::cout << "Failed to load font" << std::endl;
    }
    temp.setFont(font);
    // Assigning words
    temp.setString(input);
    // Assigning color
    temp.setColor(sf::Color::White);
    // Assigning Size
    temp.setCharacterSize(75);
    // Assigning Position
    temp.setPosition(100,100);
}