
# Udacity SDCND:  PID Control Project

## Reflection:

### Describe the effect each of the P, I, D components had in your implementation.
<strong>The P-parameter.</strong> 
This determines the influence of the direct cross-track-error measurement on the steering angle. Hence, this value determines to what degree the size of the cross-track error will affect the steering value.

<strong>The I-parameter.</strong> 
The I parameter defines the influence of the sum of the cross-track errors on the steering measurement (the integral of the cross-track errors over time). The I-parameter helps correct any steering biases over time. This parameter value should usually be very small. The idea being that for a car with some steering bias (either steering to the left / to the right), the I-parameter defines the speed with which this is corrected.
    
<strong>The D-parameter.</strong> 
This defines the influence of the change in the cross-track error measurement on the steering angle (the first derivative). This tends to control the "smoothness" of the steering and prevents overshoot.


To visualise the effect of the D-parameter, first consider a demo where the D-parameter has been set to zero and the controller drives merely with respect to the directly measured cross-track error. Notice the constant overshoot:

![demo](giphy1.gif)
(https://youtu.be/Q3USuGMi4kY)

Now we try to smooth this by steering opposite to the change in cross-track errors, essentially smoothing out the steering curve and preventing an overshoot:

![demo](giphy2.gif)
(https://youtu.be/yUAaXpz6g7Y)



### Describe how the final hyperparameters were chosen.

The hyperparameters were chosen by manual tuning and a novel technique called Twiddle. This involves measuring the cumulative cross-track error and adjusting parameters based on the improvement / deteriation of the cross-track error after the adjustement (similar to stochastic gradient descent).
