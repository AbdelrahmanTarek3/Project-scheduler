#pragma once
class MyPair {
public:
    MyPair() : IO_R(0), IO_D(0) {}
    MyPair(int IO_R, int IO_D) : IO_R(IO_R), IO_D(IO_D) {}

    int getIO_R() const { return IO_R; }
    int getIO_D() const { return IO_D; }

    void setIO_R(int IO_R) { this->IO_R = IO_R; }
    void setIO_D(int IO_D) { this->IO_D = IO_D; }

private:
    int IO_R;
    int IO_D;
};