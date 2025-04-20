# 🐧 Embedded Linux Projects & Practice – By Ziad Mohamed Fathy

This repository contains my practical learning journey with **Embedded Linux** development.  
It includes notes, hands-on experiments, mini-projects, and practical implementations focused on real-world applications using tools like:

- Yocto Project
- Buildroot
- U-Boot
- BusyBox
- Device Tree
- Kernel Modules
- System Programming in C
- GPIO, I2C, UART interfacing
- Shell scripting for embedded targets

---

## 📂 Structure

```
├── kernel_modules/        # Custom drivers and kernel-level experiments
├── buildroot_projects/    # Experiments using Buildroot for lightweight distros
├── yocto_layers/          # Custom Yocto layers and configuration
├── device_tree/           # Practice on DTS/DTB configuration
├── user_space/            # C & Bash user space programs
├── scripts/               # Utility & automation scripts
├── notes/                 # Summarized learning notes & resources
└── README.md
```

---

## 🎯 Goals of This Repo

- Understand low-level Linux components in embedded contexts
- Practice building and customizing embedded Linux distributions
- Work with real hardware (e.g. Raspberry Pi, BeagleBone, STM32MP1)
- Explore kernel space vs user space programming
- Master embedded debugging and optimization

---

## ⚙️ Tools & Technologies

- **Languages**: C, Bash
- **Build Systems**: Make, CMake
- **Linux Tools**: U-Boot, BusyBox, systemd
- **Dev Boards**: Raspberry Pi, STM32MP157, BeagleBone Black
- **Debugging**: GDB, strace, dmesg, printk

---

## 🚀 Getting Started

Most projects inside are standalone. Each folder has a mini README or comments to guide you.

For Buildroot/Yocto-based examples:
```bash
cd buildroot_projects/basic_demo
make menuconfig
make
```

---

## 👨‍💻 Author

**Ziad Mohamed Fathy**  
🔗 [LinkedIn](https://www.linkedin.com/in/ziad-fathy)  
📂 [Other Repos](https://github.com/ziadmohamed0)

---

## ⭐ Contributions

This is a personal learning repo, but feel free to open issues or suggest enhancements.  
Pull requests are welcome if you find bugs or want to improve examples.

---

## 📚 Useful Resources

- [Bootlin – Embedded Linux training](https://bootlin.com/training/)
- [Yocto Project Documentation](https://docs.yoctoproject.org/)
- [Buildroot Manual](https://buildroot.org/downloads/manual/manual.html)

---
