#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h" // support for user defined types

enum class testing {
	a = 1,
	b = 3,
	c = 9
};

template<>
struct fmt::formatter<testing> : formatter<string_view> {
public:
    template <typename FmtContext>
    constexpr auto format(testing const &t, FmtContext& ctx) const {
        const char* str;
        switch (t)
        {
            case testing::a:
                str = "a";
                break;
            case testing::b:
                str = "b";
                break;
            case testing::c:
                str = "c";
            default:
                str = "unknown ValveStateComplex state";
                break;
        }

        return formatter<string_view>::format(str, ctx);
    }
};


namespace example_namespace {

class someclass {
private:
	enum class someinternalvalue {
		these = 2,
		are = 9,
		examples = 10
	};

	someinternalvalue val;

public:
	someclass() : val(someinternalvalue::are){
	}

	void somefunction() {
		spdlog::info("{}", val);
	}
};

}

template<>
struct fmt::formatter<example_namespace::someclass::someinternalvalue> : formatter<string_view> {
public:
    template <typename FmtContext>
    constexpr auto format(example_namespace::someclass::someinternalvalue const &t, FmtContext& ctx) const {
        const char* str;
        switch (t)
        {
            case example_namespace::someclass::someinternalvalue::these:
                str = "these";
                break;
            case example_namespace::someclass::someinternalvalue::are:
                str = "are";
                break;
            case example_namespace::someclass::someinternalvalue::examples:
                str = "examples";
            default:
                str = "unknown ValveStateComplex state";
                break;
        }

        return formatter<string_view>::format(str, ctx);
    }
};

int main()
{
    spdlog::info("Welcome to spdlog!");

    testing t = testing::a;
    spdlog::info("{}", t);

    example_namespace::someclass sclass;
    sclass.somefunction();
}
