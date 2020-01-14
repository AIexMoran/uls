# uls
### Installation:
>1. git clone --recursive  
>2. make
>3. ./uls [-ACGRSTUacdfglorux1] [file ...]
### Description:
Implementation of MacOS ls

| Flag |                         Description                        |
|:----:|:----------------------------------------------------------:|
|   A  | List all entries except for . and ..                       |
|   C  | Force multi-column output                                  |
|   G  | Enable colorized output                                    |
|   R  | Recursively list subdirectories encountered                |
|   S  | Sort files by size                                         |
|   T  | Display full time                                          |
|   U  | Use time of file creation                                  |
|   a  | Include directory entries whose names begin with a dot     |
|   c  | Use time when file status was last changed                 |
|   d  | Directories are listed as plain files                      |
|   f  | Output is not sorted                                       |
|   g  | Suppressed owner name                                      |
|   l  | List in long format                                        |
|   o  | Suppressed group                                           |
|   r  | Reverse the order of the sort                              |
|   u  | Use time of last access                                    |
|   x  | Multi-column output is produced with entries sorted across |
|   1  | Force output to be one entry per line                      |
