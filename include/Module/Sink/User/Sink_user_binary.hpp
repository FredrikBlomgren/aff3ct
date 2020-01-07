/*!
 * \file
 * \brief Class module::Sink_user_binary.
 */
#ifndef SINK_USER_BINARY_HPP
#define SINK_USER_BINARY_HPP

#include <fstream>
#include <cstddef>
#include <string>
#include <vector>

#include "Module/Sink/Sink.hpp"

namespace aff3ct
{
namespace module
{
/*!
 * \class Sink_user_binary
 *
 * \brief Send data to a binary file.
 *
 * \tparam B: type of the data to send or receive.
 *
 */
template <typename B = int>
class Sink_user_binary : public Sink<B>
{
private:
	std::ofstream sink_file;
	std::vector<char> chunk;
	std::vector<B> reconstructed_buffer;
	size_t n_left; // number of bits left by last call

public:
	/*!
	 * \brief Constructor.
	 *
	 * \param N: Radio_frame length.
	 * \param n_frames: number of frames.
	 */
	Sink_user_binary(const int N, const std::string &filename, const int n_frames = 1);

	/*!
	 * \brief Destructor.
	 */
	~Sink_user_binary() = default;

protected:
	virtual void _send(const B *V, const int frame_id);
};

}
}

#endif /* SINK_USER_BINARY_HPP */
