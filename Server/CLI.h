#pragma once

namespace Messanger
{
	class CLI
	{
	public:

		virtual void help() = 0;

		virtual ~CLI() = default;
	};
}