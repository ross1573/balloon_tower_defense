#include "Shape.h"


template <int VN, int TN> Shape<VN, TN>::Shape(const glm::vec3 &center_, const glm::vec3 &color_, const Transform_Data &transform_)
{ assert("ERROR::BASE CLASS::SHAPE::CONSTRUCTOR"); }
template <int VN, int TN> Shape<VN, TN>::Shape(const glm::vec3 verticies_[VN], const glm::vec3 &color_, const Transform_Data &transform_)
{ assert("ERROR::BASE CLASS::SHAPE::CONSTRUCTOR"); }
template <int VN, int TN> void Shape<VN, TN>::init_vertex(const glm::vec3 *vertices_) { for (int i = 0; i < VN; i++) _vertices[i] = vertices_[i]; }
template <int VN, int TN> void Shape<VN, TN>::init_color(const glm::vec3 &color_) { for (int i = 0; i < VN; i++) _color[i] = color_; }
template <int VN, int TN> void Shape<VN, TN>::init_transform(const Transform_Data &transform_)
{ _transform = glm::translate(transform_.translate) * glm::rotate(glm::radians(transform_.rotate), glm::vec3(0.0f, 0.0f, 1.0f)) * glm::scale(transform_.scale); }


template <> void Shape<3, 1>::init_vertex(const glm::vec3 &center_);
template <> void Shape<3, 1>::init_indices();
template <> Shape<3, 1>::Shape(const glm::vec3 &center_, const glm::vec3 &color_, const Transform_Data &transform_) {
    init_vertex(center_);
    init_indices();
    init_color(color_);
    init_transform(transform_);
    _type = TYPE_TRIANGLE;
}

template <> Shape<3, 1>::Shape(const glm::vec3 *vertices_, const glm::vec3 &color_, const Transform_Data &transform_) {
    init_vertex(vertices_);
    init_indices();
    init_color(color_);
    init_transform(transform_);
    _type = TYPE_TRIANGLE;
}

template <> void Shape<3, 1>::init_vertex(const glm::vec3 &center_) {
    _vertices[0] = center_ + glm::vec3(-0.5f, -0.5f, 0.0f);
    _vertices[1] = center_ + glm::vec3( 0.5f, -0.5f, 0.0f);
    _vertices[2] = center_ + glm::vec3( 0.0f,  0.5f, 0.0f);
}

template <> void Shape<3, 1>::init_indices() {
    _indices[0] = 0;
    _indices[1] = 1;
    _indices[2] = 2;
}


template <> void Shape<4, 2>::init_vertex(const glm::vec3 &center_);
template <> void Shape<4, 2>::init_indices();
template <> Shape<4, 2>::Shape(const glm::vec3 &center_, const glm::vec3 &color_, const Transform_Data &transform_) {
    init_vertex(center_);
    init_indices();
    init_color(color_);
    init_transform(transform_);
    _type = TYPE_SQUARE;
}

template <> Shape<4, 2>::Shape(const glm::vec3 *vertices_, const glm::vec3 &color_, const Transform_Data &transform_) {
    init_vertex(vertices_);
    init_indices();
    init_color(color_);
    init_transform(transform_);
    _type = TYPE_SQUARE;
}

template <> void Shape<4, 2>::init_vertex(const glm::vec3 &center_) {
    _vertices[0] = center_ + glm::vec3(-0.5f, -0.5f, 0.0f);
    _vertices[1] = center_ + glm::vec3(-0.5f,  0.5f, 0.0f);
    _vertices[2] = center_ + glm::vec3( 0.5f,  0.5f, 0.0f);
    _vertices[3] = center_ + glm::vec3( 0.5f, -0.5f, 0.0f);
}

template <> void Shape<4, 2>::init_indices() {
    _indices[0] = 0;
    _indices[1] = 1;
    _indices[2] = 3;
    _indices[3] = 1;
    _indices[4] = 2;
    _indices[5] = 3;
}
