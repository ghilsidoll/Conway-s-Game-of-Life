#include "cell.hpp"

ui::cell::cell(const float cell_size) :cell_shape_(sf::RectangleShape(sf::Vector2f(cell_size, cell_size)))
{
	cell_shape_.setFillColor(sf::Color::Transparent);
}

void ui::cell::set_status(const bool status)
{
	status ? cell_shape_.setFillColor(ALIVE_CELL_COLOR) : cell_shape_.setFillColor(DEAD_CELL_COLOR);
}

void ui::cell::draw(sf::RenderWindow& window, const float x_position, const float y_position)
{
	cell_shape_.setPosition(x_position, y_position);
	window.draw(cell_shape_);
}

bool ui::cell::is_mouse_over(const sf::RenderWindow& window) const
{
	return cell_shape_.getGlobalBounds().contains(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
}
