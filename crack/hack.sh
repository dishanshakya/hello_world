#!/bin/bash

hist=$(cat history)
./generator $hist | ./filter 2 | ./lastpass  
