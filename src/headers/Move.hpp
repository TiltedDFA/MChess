#pragma once
struct Move
{
    template<typename T, typename V>
    constexpr Move(T start, V end)noexcept :
     startIndex(static_cast<short>(start)),
     endIndex(static_cast<short>(end)){}
    const short startIndex;
    const short endIndex;
};
