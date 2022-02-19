import { Component, OnInit } from '@angular/core';
import { AbstractControl, FormControl, FormGroup } from '@angular/forms';
import { Router } from '@angular/router';
import { DataService } from 'src/app/services/data.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})
export class RegisterComponent implements OnInit {

  public registerForm: FormGroup = new FormGroup({
    firstName: new FormControl(''),
    lastName: new FormControl(''),
    email: new FormControl(''),
    password: new FormControl('')
  });

  constructor(
    private router: Router,
    private dataService: DataService
  ) { }

  get firstName(): AbstractControl {
    return this.registerForm?.get('firstName') as AbstractControl;
  }
  get lastName(): AbstractControl {
    return this.registerForm?.get('lastName') as AbstractControl;
  }
  get email(): AbstractControl {
    return this.registerForm?.get('email') as AbstractControl;
  }
  get password(): AbstractControl {
    return this.registerForm?.get('password') as AbstractControl;
  }

  ngOnInit() {
    localStorage.clear();
  }

  public register(): void {
    console.log(this.registerForm.value);
    
    this.dataService.registerUser(this.registerForm.value).subscribe({
      next: (result) => {
        console.log(result);
        this.router.navigate(['../auth/login']);
      },
      error: (e) => {
        console.error(e);
        window.alert('Invalid register data.');
        window.location.reload();
      }
    });
  }
}