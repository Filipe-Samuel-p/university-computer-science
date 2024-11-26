package com.example.projectOOP.controllers;




import com.example.projectOOP.entities.Film;
import com.example.projectOOP.entities.User;
import com.example.projectOOP.service.FilmService;
import com.example.projectOOP.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

import jakarta.servlet.http.HttpSession;

import java.util.List;

@Controller
public class WebController {

    @Autowired
    private FilmService filmService;

    @Autowired
    private UserService userService;

    @GetMapping("/")
    public String index(Model model, HttpSession session) {
        List<Film> films = filmService.findAll();
        model.addAttribute("films", films);
        model.addAttribute("user", session.getAttribute("user"));
        return "index";
    }

    @GetMapping("/login")
    public String loginForm() {
        return "login";
    }

    @PostMapping("/login")
    public String login(@RequestParam String email, @RequestParam String password, HttpSession session) {
        User user = userService.findByEmailAndPassword(email, password);
        if (user != null) {
            session.setAttribute("user", user);
            return "redirect:/";
        }
        return "redirect:/login?error";
    }

    @GetMapping("/logout")
    public String logout(HttpSession session) {
        session.removeAttribute("user");
        return "redirect:/";
    }

    @GetMapping("/register")
    public String registerForm() {
        return "register";
    }

    @PostMapping("/register")
    public String register(@RequestParam String name, @RequestParam String email, @RequestParam String password) {
        User user = new User(null, name, password, email, null);
        userService.insert(user);
        return "redirect:/login";
    }

}
