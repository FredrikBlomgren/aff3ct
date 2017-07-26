#ifndef FACTORY_DECODER_RA_HPP
#define FACTORY_DECODER_RA_HPP

#include <string>

#include "Module/Decoder/Decoder.hpp"

#include "Factory/Module/Interleaver.hpp"

#include "../Decoder.hpp"

namespace aff3ct
{
namespace factory
{
struct Decoder_RA : public Decoder
{
	static const std::string name;
	static const std::string prefix;

	struct parameters : Decoder::parameters
	{
		virtual ~parameters() {}

		int n_ite = 10;

		Interleaver::parameters itl;
	};

	template <typename B = int, typename R = float>
	static module::Decoder<B,R>* build(const parameters &params, const module::Interleaver<int> &itl);

	static void build_args(arg_map &req_args, arg_map &opt_args, const std::string p = prefix);
	static void store_args(const arg_val_map &vals, parameters &params, const std::string p = prefix);
	static void make_header(params_list& head_dec, params_list& head_itl, const parameters& params, const bool full = true);
};
}
}

#endif /* FACTORY_DECODER_RA_HPP */
