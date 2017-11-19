echo mounting kenaxos.img to /docks/dock01/sys/kernel
sudo mount -o loop -t vfat /home/kenneth/KenaxOS/kenaxos.img /docks/dock01
ls /docks/dock01/sys/kernel
echo removing old kernel.bin in kenaxos.img
sudo rm /docks/dock01/sys/kernel/kernel.bin
ls /docks/dock01/sys/kernel
echo copying new kernel.bin to kenaxos.img from ~/KenaxOS/GRUB_BOOT to /docks/dock01/sys/kernel.
sudo cp /home/kenneth/KenaxOS/0.3/kernel.bin /docks/dock01/sys/kernel
ls /docks/dock01/sys/kernel
echo unmounting kenaxos.img.
sudo umount /home/kenneth/KenaxOS/kenaxos.img
