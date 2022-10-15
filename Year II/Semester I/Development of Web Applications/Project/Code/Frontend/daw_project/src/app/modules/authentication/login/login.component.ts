import { Component, OnInit } from '@angular/core';
import { AbstractControl, FormControl, FormGroup } from '@angular/forms';
import { Router } from '@angular/router';
import { DataService } from 'src/app/services/data.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {

  public loginForm: FormGroup = new FormGroup({
    email: new FormControl(''),
    password: new FormControl('')
  });

  constructor(
    private router: Router,
    private dataService: DataService
  ) { }

  get email(): AbstractControl {
    return this.loginForm?.get('email') as AbstractControl;
  }
  get password(): AbstractControl {
    return this.loginForm?.get('password') as AbstractControl;
  }

  ngOnInit() {
    localStorage.clear();
  }

  public login(): void {
    console.log(this.loginForm.value);
    
    this.dataService.changeUserData(this.loginForm.value);
    this.dataService.loginUser(this.loginForm.value).subscribe({
      next: (result) => {
        // console.log(result);
        
        localStorage.setItem("jwt", result.token);

        if (result.token) {
          if (this.loginForm.value.email.toLowerCase().includes("admin")) {
            localStorage.setItem('Role', 'Admin');
          } else {
            localStorage.setItem('Role', 'User');
          }
          this.router.navigate(['../pc-components']);
        } else {
          window.alert('Invalid login credentials.');
          window.location.reload();
        }
      },
      error: (e) => {
        console.error(e);
        window.location.reload();
      }
    });
  }
}