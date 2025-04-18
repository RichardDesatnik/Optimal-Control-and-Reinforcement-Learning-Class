# HW3 Spring 2023

**Due Wednesday 4/5 11:59 PM Eastern.**

## Instructions

In this homework, we are ready to start solving some nonlinear trajectory optimization problems. We will explore two common methods in questions one and two, followed by an open ended question where you may choose to use whichever technique you prefer to accomplish a set of control objectives. 

1. Solve for a cartpole swingup trajectory using NonLinear Programming (NLP) with IPOPT via direct collocation. 

2. Solve for an aggressive quadrotor aerobatic manuever using iLQR. 

3. Use whichever tool(s) you prefer to generate collision free trajectories for three planar quadrotors. 

## Submission 

Use any method you like to export your jupyter notebook as a PDF (with all the cell outputs shown), and submit on gradescope. Here are some methods for creating this PDF: [https://mljar.com/blog/jupyter-notebook-pdf/](https://mljar.com/blog/jupyter-notebook-pdf/). 

## Notes 

- These questions will have long outputs for each cell, remember you can use `cell -> all output -> toggle scrolling` to better see all of the output without having to scroll. 

- IPOPT can take a long time for certain problems. In Jupyter Notebooks, IPOPT will not output anything until IPOPT is finished. If you find that IPOPT is hanging for a long time, it may be that IPOPT is running and taking a very long time (which likely means something else is wrong). To see the output of IPOPT in real time, you have to call the script from the Julia REPL. To do this, you can run the following in the REPL:

```julia 
using NBInclude
@nbinclude("Q1.ipynb")
```

## Version History

As bugs show up, they will be addressed on both Piazza as well as this readme.
