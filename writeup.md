# Writeup

In the following I will elaborate on the points of the project rubric and decribe the code for the PID Controller.

## Project Rubric Points

### **Your code should compile.**
The compilation with `cmake` does not return any errors on WSL.

### **The PID procedure follows what was taught in the lessons.**
I transferred the learnings from the lessons to this project.

## Reflection

### **Describe the effect each of the P, I, D components had in your implementation.**
By only using the proportional gain `Kp` the vehicle is able to keep the track at first, but the overshooting increases and soon the controller is not able to keep the car on track.
By only using the integral gain `Ki` the vehicle is only going in circles with maximum steering angle (positive and negative). The integral gain can be used for eliminating biases or drifts in the steering, which are not present in this project.
By only using the diffential gain `Kd`, the car is going going very smooth, i.e. the steering angles are not changing a lot. However, the controller is not able to keep the car on track since the control outputs (steering angles) are too small / soft and therefore not very effective on its own. If used together with the proportional gain, the differential proportion minimize the flaws of overshooting. This is a very effective combination.

### **Describe how the final hyperparameters were chosen.**
As described above, at first an approach was chosen to set tweo of the three parameters `[Kd, Ki, Kp]` to zero, while the other was set to one, similar to the Twiddling procedure presented by Sebastian.

However, instead of implementing a twiddling algorithm, it was deduced from the results of setting each parameter to one that  `Ki` is not effective in this particular case ((with no bias present) and can be set to zero.

The values for `Kp, Kd` were derived by manually tuning and checking the result with the simulator. The final values are `Kp = 0.25, Kd = 3.5`