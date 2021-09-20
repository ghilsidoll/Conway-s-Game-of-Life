#include "engine.h"

cr::engine::engine(const int i, const int j)
	: current_state_(std::vector<std::vector<bool>>(i, std::vector<bool>(j, false)))
{ }

void cr::engine::make_step()
{
	next_state_ = current_state_;
	for (size_t i = 0; i < current_state_.size(); i++)
	{
		for (size_t j = 0; j < current_state_[i].size(); j++)
		{
			check_neighbors(static_cast<int>(i), static_cast<int>(j));
		}
	}
	current_state_ = next_state_;
}

void cr::engine::set_state_status(const int i, const int j, bool status)
{
	current_state_[i][j] = status;
}

bool cr::engine::get_state_status(const int i, const int j) const
{
	return current_state_[i][j];
}

void cr::engine::check_neighbors(const int i, const int j)
{
	int neighbors_counter = 0;
	for (auto& position : neighbors_position_)
	{
		if (current_state_[i + position[0] < 0 ? current_state_.size() - 1 : 
			i + position[0] > static_cast<int>(current_state_.size()) - 1 ? 0 : i + position[0]][j + position[1] < 0 ? static_cast<int>(current_state_[0].size()) - 1 :
			j + position[1] > static_cast<int>(current_state_[0].size()) - 1 ? 0 : j + position[1]] == true)
		{
			neighbors_counter++;
		}
	}
	next_state_[i][j] = current_state_[i][j] == true && (neighbors_counter > 3 || neighbors_counter < 2) ? false : neighbors_counter == 3 ? true : next_state_[i][j];
}
