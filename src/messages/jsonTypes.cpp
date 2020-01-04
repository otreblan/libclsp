// A C++17 library for language servers.
// Copyright © 2019-2020 otreblan
//
// libclsp is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libclsp is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libclsp.  If not, see <http://www.gnu.org/licenses/>.

#include <libclsp/messages/jsonTypes.hpp>
#include <libclsp/messages/objectT.hpp>

namespace libclsp
{

using namespace std;

Number operator+(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i + j;
				},
				[&ret, i](double j)
				{
					ret = i + j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i + j;
				},
				[&ret, i](double j)
				{
					ret = i + j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator-(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i - j;
				},
				[&ret, i](double j)
				{
					ret = i - j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i - j;
				},
				[&ret, i](double j)
				{
					ret = i - j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator*(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i * j;
				},
				[&ret, i](double j)
				{
					ret = i * j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i * j;
				},
				[&ret, i](double j)
				{
					ret = i * j;
				}
			), n2);
		}
	), n1);

	return ret;
}

Number operator/(Number const &n1, Number const &n2)
{
	Number ret;

	visit(overload
	(
		[&ret, &n2](int i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i / j;
				},
				[&ret, i](double j)
				{
					ret = i / j;
				}
			), n2);
		},
		[&ret, &n2](double i)
		{
			visit(overload
			(
				[&ret, i](int j)
				{
					ret = i / j;
				},
				[&ret, i](double j)
				{
					ret = i / j;
				}
			), n2);
		}
	), n1);

	return ret;
}


Number& operator+=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i + j;
				},
				[&n1, i](double j)
				{
					n1 = i + j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i + j;
				},
				[&n1, i](double j)
				{
					n1 = i + j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator-=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i - j;
				},
				[&n1, i](double j)
				{
					n1 = i - j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i - j;
				},
				[&n1, i](double j)
				{
					n1 = i - j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator*=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i * j;
				},
				[&n1, i](double j)
				{
					n1 = i * j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i * j;
				},
				[&n1, i](double j)
				{
					n1 = i * j;
				}
			), n2);
		}
	), n1);

	return n1;
}

Number& operator/=(Number &n1, Number const &n2)
{
	visit(overload
	(
		[&n1, &n2](int i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i / j;
				},
				[&n1, i](double j)
				{
					n1 = i / j;
				}
			), n2);
		},
		[&n1, &n2](double i)
		{
			visit(overload
			(
				[&n1, i](int j)
				{
					n1 = i / j;
				},
				[&n1, i](double j)
				{
					n1 = i / j;
				}
			), n2);
		}
	), n1);

	return n1;
}
}
