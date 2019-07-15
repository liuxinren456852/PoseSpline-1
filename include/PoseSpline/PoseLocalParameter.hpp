#ifndef POSELOCALPARAMETER_H
#define POSELOCALPARAMETER_H


#include <eigen3/Eigen/Dense>
#include <ceres/ceres.h>
#include "PoseSpline/LocalParamizationAdditionalInterfaces.hpp"


/*
 * PoseLocalParameter
 * Hers we define the pose representaion: first translate , then rotation quaternion
 */
class PoseLocalParameter: public  ceres::LocalParameterization,
                                LocalParamizationAdditionalInterfaces{


public:
    virtual ~PoseLocalParameter() {};
    virtual bool Plus(const double *x, const double *delta, double *x_plus_delta) const;
    virtual bool ComputeJacobian(const double *x, double *jacobian) const;
    virtual int GlobalSize() const { return 7; };
    virtual int LocalSize() const { return 6; };

    static bool plus(const double* x, const double* delta, double* x_plus_delta);


    // Extent interface
    virtual bool ComputeLiftJacobian(const double* x, double* jacobian) const ;
    static bool liftJacobian(const double* x,double* jacobian);
    static bool plusJacobian(const double* x,double* jacobian);
    bool VerifyJacobianNumDiff(const double* x, double* jacobian,double* jacobianNumDiff);
};


#endif