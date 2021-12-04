#pragma once

/**
 * \brief the details
 *       [1] class type
 *              0. Rectangle<_Ty>
 *              1. RefRectangle<_Ty>
 * 
 *       [2] methods for Line
 *              0. area
 *              1. perimeter
 *              2. operator "<<" for Rectangle<_Ty>
 *              3. operator "<<" for RefRectangle<_Ty>
 */

#include "point.hpp"

namespace ns_geo
{
    template <typename _Ty>
    class Rectangle;
    using Rectangled = Rectangle<double>;
    using Rectanglef = Rectangle<float>;
    using Rectanglei = Rectangle<int>;

    /**
     * \brief a sample template class to describe the 2-dime rectangles
     */
    template <typename _Ty = float>
    class Rectangle
    {
    public:
        using value_type = _Ty;
        using point_type = ns_geo::Point2<value_type>;

    private:
        // top left point
        point_type _tplp;
        // lower right point
        point_type _lwrp;

    public:
        Rectangle() = default;
        Rectangle(const point_type &topLeft, const point_type &lowerRight)
            : _tplp(topLeft), _lwrp(lowerRight) {}
        Rectangle(const point_type points[2])
            : _tplp(points[0]), _lwrp(points[1]) {}
        Rectangle(const std::array<point_type, 2> &points)
            : _tplp(points[0]), _lwrp(points[1]) {}
        Rectangle(value_type tlx, value_type tly, value_type lrx, value_type lry)
            : _tplp(tlx, tly), _lwrp(lrx, lry) {}

        std::array<point_type, 2> points() const { return std::array<point_type, 2>{this->_tplp, this->_lwrp}; }

        const point_type &topLeft() const { return this->_tplp; }

        point_type &topLeft() { return this->_tplp; }

        const point_type &lowerRight() const { return this->_lwrp; }

        point_type &lowerRight() { return this->_lwrp; }

        float area() const { return std::abs(this->_tplp.x() - this->_lwrp.x()) * std::abs(this->_tplp.y() - this->_lwrp.y()); }

        float perimeter() const
        {
            return 2.0 * (std::abs(this->_tplp.x() - this->_lwrp.x()) + std::abs(this->_tplp.y() - this->_lwrp.y()));
        }
    };

    template <typename _Ty = float>
    std::ostream &operator<<(std::ostream &os, const Rectangle<_Ty> &rect)
    {
        os << '{';
        os << rect.topLeft() << ", ";
        os << rect.lowerRight() << '}';
        return os;
    }
#pragma region RefRectangle

    using RefRectangled = RefRectangle<double>;
    using RefRectanglef = RefRectangle<float>;
    using RefRectanglei = RefRectangle<int>;

    template <typename _Ty = float>
    class RefRectangle
    {
    public:
        using value_type = _Ty;
        using refpoint_type = ns_geo::RefPoint2<value_type>;
        using refpointset_type = RefPointSet2<value_type>;

    public:
        friend class RefPointSet2<value_type>;

    private:
        // top left point's id
        uint _tplpid;
        // lower right point's id
        uint _lwrpid;
        // thr reference point set's pointer 
        const refpointset_type *_rps;

    protected:
        RefRectangle(uint topLeftID, uint lowerRightID, const refpointset_type *refpointset)
            : _tplpid(topLeftID), _lwrpid(lowerRightID), _rps(refpointset) {}

    public:
        RefRectangle() = delete;
        
        const refpointset_type *refPointSet() const { return this->_rps; };

        std::array<refpoint_type, 2> points() const
        {
            return std::array<refpoint_type, 2>{_rps->at(this->_tplpid), _rps->at(this->_lwrpid)};
        }

        const refpoint_type &topLeft() const { return _rps->at(this->_tplpid); }

        refpoint_type &topLeft() { return _rps->at(this->_tplpid); }

        const refpoint_type &lowerRight() const { return _rps->at(this->_lwrpid); }

        refpoint_type &lowerRight() { return _rps->at(this->_lwrpid); }

        float area() const
        {
            return std::abs(this->topLeft().x() - this->lowerRight().x()) *
                   std::abs(this->topLeft().y() - this->lowerRight().y());
        }

        float perimeter() const
        {
            return 2.0 * (std::abs(this->topLeft().x() - this->lowerRight().x()) +
                          std::abs(this->topLeft().y() - this->lowerRight().y()));
        }
    };

    template <typename _Ty = float>
    std::ostream &operator<<(std::ostream &os, const RefRectangle<_Ty> &rect)
    {
        auto p1 = rect.topLeft();
        auto p2 = rect.lowerRight();
        os << '{';
        os << p1.id() << ": [" << p1.x() << ", " << p1.y() << ']' << ", ";
        os << p2.id() << ": [" << p2.x() << ", " << p2.y() << "]}";
        return os;
    }
#pragma endregion
} // namespace ns_geo
