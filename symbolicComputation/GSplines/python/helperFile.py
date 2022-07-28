import numpy as np 
from sympy import *
from sympy.physics.vector import *
import matplotlib.colors as mcolors
import matplotlib.pyplot as plt

def indexed_variable(Sym,i):
    return Symbol(''.join([Sym,'_',str(i)]))

def drawCircles(angle,radius):
    nbSample=2000
    angleSamples = np.linspace( 0 , angle , nbSample )
    x = radius * np.cos( angleSamples ) 
    y = radius * np.sin( angleSamples ) 
    return x,y


def ploter(df):
    cm = 1/2.54 
    figure, axes = plt.subplots(1,figsize=(21*cm, 21*cm),linewidth=1.22)
    figureTotal, axesTotal = plt.subplots(1,figsize=(21*cm, 21*cm),linewidth=1.22)
    axes.axis('off')
    axes.set_aspect( 1 )
    axesTotal.axis('off')
    axesTotal.set_aspect( 1 )
    i=1
    x,y=drawCircles(
        (360-float(df.loc[i,"alpha"]))*np.pi/180,
        df.loc[i,"VoidRadius(OnPlane)"])
    x=[j for j in x]
    y=[j for j in y]
    maxx=max(x)
    y=[j for j in y]
    maxy=max(y)
    Xsupport=[]
    Ysupport=[]
    for i in range (1,len(df.index)):
        cc=np.random.rand(3)
        x,y=drawCircles(
            (360-float(df.loc[i,"alpha"]))*np.pi/180,
            df.loc[i,"VoidRadius(OnPlane)"])
        x=[j for j in x]
        y=[j for j in y]
        axesTotal.plot( x, y,color=cc, linewidth=1.22)
        if (i % 4 ==1):
            x=[i+maxx*2 for i in x]
        if (i % 4 ==2):
            x=[i+maxx*4 for i in x]
        if (i % 4 ==3):
            x=[i+maxx*6 for i in x]
        axes.plot( x, y,color=cc, linewidth=1.22)

        pt1=[x[-1],y[-1]]
        pt1p=[x[0],y[0]]

        x,y=drawCircles(
            (360-float(df.loc[i,"alpha"]))*np.pi/180,
            df.loc[i,"VoidRadius(OnPlane)"]+df.loc[i,"couroneRadius(OnPlane)"])
        x=[j for j in x]
        y=[j for j in y]

        axesTotal.plot( x, y,color=cc, linewidth=1.22)
        if (i % 4 ==1):
            x=[i+maxx*2 for i in x]
        if (i % 4 ==2):
            x=[i+maxx*4 for i in x]
        if (i % 4 ==3):
            x=[i+maxx*6 for i in x]
        axes.plot( x, y,color=cc, linewidth=1.22)
        pt2=[x[-1],y[-1]]
        pt2p=[x[0],y[0]]
        axes.plot( [pt1[0],pt2[0]], [pt1[1],pt2[1]],color=cc, linewidth=1.22)
        axes.plot( [pt1p[0],pt2p[0]], [pt1p[1],pt2p[1]],color=cc, linewidth=1.22)
        # adding the support
        Xsupport+=[df.loc[i,"X1"][0]]
        Xsupport+=[df.loc[i,"X2"][0]]
        Ysupport+=[df.loc[i,"X1"][1]]
        Ysupport+=[df.loc[i,"X2"][1]]
        #axes.axis('off')
        axes.set_aspect( 1 )
        filename="file/conIm"+str(i)+"png"
        plt.savefig(filename,orientation= 'portrait')
        axes.clear()
    minsupportY=min(Ysupport)
    maxsupportY=max(Ysupport)
    minsupportX=min(Xsupport)
    maxsupportX=max(Xsupport)

    Xsupport=[minsupportX]+Xsupport
    Ysupport=[minsupportY-0.1*abs(minsupportY)]+Ysupport

    Xsupport=Xsupport+[maxsupportX]
    Ysupport=Ysupport+[minsupportY-0.1*abs(minsupportY)]


    maxx=max(Xsupport)
    Xsupport=[i+5*maxx for i in Xsupport]
    axes.plot(Xsupport,Ysupport,linewidth=0.2)


    #axes.axis('off')
    axes.set_aspect( 1 )

    plt.savefig("file/ConSupport.pdf",orientation= 'portrait')






