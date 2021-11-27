#pragma once

#include "point.hpp"

namespace ns_geo
{
#pragma region Line2
    template <typename _Ty>
    class Line2;
    using Line2d = Line2<double>;
    using Line2f = Line2<float>;
    using Line2i = Line2<int>;

    /**
     * \brief a sample template class to describe the 2-dime lines
     */
    template <typename _Ty = float>
    class Line2
    {
    public:
        using value_type = _Ty;
        using point_type = ns_geo::Point2<_Ty>;

    private:
        point_type _p1;
        point_type _p2;

    public:
        Line2() = default;
        Line2(const point_type &p1, const point_type &p2)
            : _p1(p1), _p2(p2) {}
        Line2(const point_type points[2])
            : _p1(points[0]), _p2(points[1]) {}
        Line2(const std::array<point_type, 2> &points)
            : _p1(points[0]), _p2(points[1]) {}

        const point_type &p1() const { return this->_p1; }
        point_type &p1() { return this->_p1; }

        const point_type &p2() const { return this->_p2; }
        point_type &p2() { return this->_p2; }

        std::array<point_type, 2> points() const { return std::array<point_type, 2>{this->_p1, this->p2}; }

        float length() const { return ns_geo::distance(_p1, _p2); }
    };

    template <typename _Ty = float>
    std::ostream &operator<<(std::ostream &os, const Line2<_Ty> &line)
    {
        os << '{';
        os << line.p1() << ", ";
        os << line.p2() << '}';
        return os;
    }
#pragma endregion

#pragma region Line3
    template <typename _Ty>
    class Line3;
    using Line3d = Line3<double>;
    using Line3f = Line3<float>;
    using Line3i = Line3<int>;

    /**
     * \brief a sample template class to describe the 3-dime lines
     */
    template <typename _Ty = float>
    class Line3
    {
    public:
        using value_type = _Ty;
        using point_type = ns_geo::Point3<_Ty>;

    private:
        point_type _p1;
        point_type _p2;

    public:
        Line3() = default;
        Line3(const point_type &p1, const point_type &p2)
            : _p1(p1), _p2(p2) {}
        Line3(const point_type points[2])
            : _p1(points[0]), _p2(points[1]) {}
        Line3(const std::array<point_type, 2> &points)
            : _p1(points[0]), _p2(points[1]) {}

        const point_type &p1() const { return this->_p1; }
        point_type &p1() { return this->_p1; }

        const point_type &p2() const { return this->_p2; }
        point_type &p2() { return this->_p2; }

        std::array<point_type, 2> points() const { return std::array<point_type, 2>{this->_p1, this->p2}; }

        float length() const { return ns_geo::distance(_p1, _p2); }
    };

    template <typename _Ty = float>
    std::ostream &operator<<(std::ostream &os, const Line3<_Ty> &line)
    {
        os << '{';
        os << line.p1() << ", ";
        os << line.p2() << '}';
        return os;
    }
#pragma endregion
} // namespace ns_geo